<?php

require_once dirname(__FILE__) . '/../geocoll/geocoll.classes.inc';      /*require_once: is used to include a php file to another one, when we may need to                                                                             include the called file more than once. If it is found the calling script will                                                                               ignore further inclusions.
                                                                          
                                                                         dirname(__FILE__). '/..turtlebase.classes.inc' : dirname() is a PHP function which returns the directory name of a file. For example if file abc.txt was in “/tmp/abc.txt” then the dirname() function would return “/tmp”        
                                                                          
                                                                          __FILE__ constantÂ  represents the running script. It will return the full path and file name of the running script. For example, theÂ  __FILE__ constantÂ  on my server would return “/var/www/html/index.php” for my index.php file which is in the “/var/www/html/” directory.    */

/**
 * Implements hook_drush_command()
 */
function geocoll_data_importer_drush_command() {

  $items = array();

  $items['geocoll-data-import'] = array(
    'description' => 'Create Drupal nodes from CSV records',
  );

  $items['geocoll-data-delete-all'] = array(
    'description' => 'Delete all nodes of imported types',
  );

  $items['geocoll-data-custom'] = array(
    'description' => 'Placeholder for code to run once',
  );

  return $items;

}

/*
* ported from geocoll_data_cleanup.r
*/
function _geocoll_data_cleanup($row) {

  foreach ($row as $key => $value) {
    $row[$key] = trim($row[$key]);
  }

  // The R cleanup script exported NA as null and downstream code expects this
  foreach ($row as $key => $value) {
    if ($row[$key] === 'NA') {
      $row[$key] = 'null';
    }
  }

  if ($row['ID-1'] === 'null' && $row['ID-2'] === 'null') {
    throw new GeocollDataEntryException(" No ID-1 and ID-2");
  }


  $row['TimeIsUnknown'] = ($row['Collection_Date'] === 'null');

  if ($row['TimeIsUnknown']) {
    $row['Collection_Date'] = '0000';
  }


function _geocoll_data_log($message) {
  drush_print(sprintf('[%s] %s', date('Y-m-d H:i:s'), $message));
}

function drush_geocoll_data_importer_geocoll_data_import() {

  /*
    Left to insert into workflow:
    BioSample
    ClimateMetData
    Hemiphoto
    LoggerData
    Logger
    LoggerWindow
    Hatchlings
    Study
  */

  if (($input_handle = fopen(dirname(__FILE__). '/bad_date_stuff_fixed_scutes_fixed_datedead.txt', 'r')) !== FALSE) {

    $header = fgetcsv($input_handle, 0, "\t");
    $header_length = count($header);

    $row_number = 0;

    while (($input_row = fgetcsv($input_handle, 0, "\t")) !== FALSE) {

      $transaction = db_transaction();

      try {

        $row = array_combine($header, array_pad($input_row, $header_length, 'NA'));

        $row = _turtle_data_cleanup($row);

        if (strtolower($row['Date']) === 'null') {
          throw new TurtleDataEntryException('No date');
        }

        // STATIC + INDIVIDUAL
        $computed_id_is_bad = FALSE;
        $computed_id = StaticCharacteristic::compute_id(StaticCharacteristic::createFromCSV(0, $row)); // what it does?

        $make_a_turtle = ($row['TrueID'] !== "null" || preg_match('/^[0-9][0]+$/', $computed_id) !== 1); // 
        $make_a_nest = ($row['Nest'] !== 'null' && ((int) $row['Nest'] > 0));

        // OBSERVATION

        if ($make_a_turtle || $make_a_nest) {
          $observation = Observation::createFromCSV($row);
          $observation->save();
        } else {
          throw new TurtleDataEntryException('Not sure what to do with this row');
        }

        //TODO: add some dup check (time and individual)

        // STATIC + INDIVIDUAL

        if ($make_a_turtle) {
        
          if ($computed_id !== $row['TrueID']) {
            $computed_id_is_bad = TRUE;
            $computed_id = $row['TrueID'];
          }

          $static_query = new TurtleDataEntityFieldQuery();
          $static_query->entityCondition('bundle', 'static');
          $static_query->fieldCondition('field_static_computed_id', 'value', $computed_id, '=');

          $static_results = $static_query->execute();

          if (!empty($static_results['node'])) {
            if (count($static_results['node']) > 1) {
              //should not be more than one
              throw new TurtleDataEntryException('Computed ID matched more than one StaticCharacteristics');
            }
            $static = new StaticCharacteristic(node_load(key($static_results['node'])));
            StaticCharacteristic::update_static_chars($static, $row);
          }
          else {

            $individual = Individual::createFromCSV($row);
            $individual->save();

            $static = StaticCharacteristic::createFromCSV($individual->nid, $row);
            if ($computed_id_is_bad) {
              $static->field_static_computed_id_is_bad[LANGUAGE_NONE][0]['value'] = 1;
              $static->field_static_computed_id[LANGUAGE_NONE][0]['value'] = $computed_id;
            }
            $static->save();
            
          }

          $individual = new Individual(node_load($static->field_static_individual_id[LANGUAGE_NONE][0]['target_id']));

          // DYNAMIC

          $dynamic_characteristic = DynamicCharacteristic::createFromCSV($individual->nid, $observation->nid, $row);
          $dynamic_characteristic->save();

        }

        if ($make_a_nest) {

          // NEST

          $nest_query = new TurtleDataEntityFieldQuery();
          // check to see if we've already created a nest for this individual for this year
          $nest_query->entityCondition('bundle', 'nest');
          $nest_query->fieldCondition('field_nest_legacy_nest_id', 'value', $row['Nest'], '=');
          $nest_query->fieldCondition('field_nest_year', 'value', $row['Year'] . '-01-01 00:00:00', '=');

          $nest_results = $nest_query->execute();

          // if the nest has not yet been created, then make it. Otherwise, get nid of existing nest.
          if (!empty($nest_results['node'])) {
            if (count($nest_results['node']) > 1) {
              //should not be more than one
              throw new TurtleDataEntryException('Found more than one nest with this ID this year');
            }
            $nest = new Nest(node_load(key($nest_results['node'])));
          }
          else {
            $nest = Nest::createFromCSV($row);
            $nest->save();
          }

          // NEST OBSERVATION

          $nest_observation = NestObservation::createFromCSV($observation->nid, $nest->nid, $row);
          $nest_observation->save();

          // EGGS

          for ($i = 1; $i < 23; $i++) {
            if ($row['egg' . $i] !== 'null') {
              $eggs = Egg::createFromCSV($nest_observation->nid, $row['egg' . $i]);
              $eggs->save();
            }
          }

        }

      } catch (Exception $e) {
        $transaction->rollback();
        $rejects_filename = dirname(__FILE__) . sprintf('/bad_date_stuff_fixed_scutes_fixed_datedead_rejects/%s.txt', $e->getMessage());
        if (($rejects_handle = fopen($rejects_filename, 'a')) !== FALSE) {
          fputcsv($rejects_handle, array_values($input_row), "\t");
          fclose($rejects_handle);
        } else {
          _turtle_data_log(sprintf('Unable to write to rejects file: %s', $rejects_filename));
        }
      }

      if (($row_number % 20) === 0) {
        _turtle_data_log(sprintf('Processed row %d.', $row_number));
      }

      unset($transaction);

      $row_number++;

    }

    fclose($input_handle);

  }

}

function drush_turtle_data_importer_turtle_data_delete_all() {

  $types = array(
    'biosample',
    'hatchling',
    'egg',
    'nobs',
    'nest',
    'dynamic',
    'observation',
    'static',
    'individual',
  );

  foreach($types as $type) {

    $results = db_select('node', 'n')
      ->fields('n', array('nid'))
      ->condition('type', $type)
      ->execute();

    $nids = $results->fetchCol();

    if (!empty($nids)) {
      foreach (array_chunk($nids, 100) as $batch_nids) {
        node_delete_multiple($batch_nids);
        drush_print(sprintf('%d nodes of %s have been deleted.', count($batch_nids), $type));
      }
    }

  }

  $serial_tables = db_query('SHOW TABLES LIKE \'serial_%\'')->fetchCol();

  foreach ($serial_tables as $table_name) {
    db_truncate($table_name)->execute();
  }

}

function drush_turtle_data_importer_turtle_data_custom() {

}

