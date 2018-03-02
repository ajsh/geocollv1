<?php
/**
 * @file
 * Drush support for features_lock_report.
 */

/**
 * Implements hook_drush_command()
 */
function features_lock_report_drush_command() {
  $items['features-lock-report'] = array(
    'description' => 'Generate a report of features overrides and locks',
    'aliases' => array('flr'),
    'options' => array(
      'summary' => 'Prints a simple summary of "OK", "Warning", or "Error" based on the worst-case component.',
    ),
    'examples' => array(
      'drush features-lock-report' => "Prints a report of all overridden Features and their lock states.",
      'drush features-lock-report --summary' => 'Prints only "OK", "Warning" or "Error" based on the worst-case component.',
    ),
  );

  return $items;
}

/**
 * Default callback for features-lock-report drush command.
 */
function drush_features_lock_report() {
  $summary = drush_get_option('summary');

  $report = features_lock_report_report($summary);

  // If the only the summary is requested, don't bother formatting the data for
  // displaying as a table.
  if ($summary) {
    echo $report;
    return;
  }

  // Generate the table header.
  $table = array (
    'header' => array(
      0 => 'Component',
      1 => 'Locked',
      2 => 'Overridden',
    ),
  );

  // Transform the report into an array that can be passed to drush_print_table().
  foreach ($report as $module => $components) {
    foreach ($components as $component => $states) {
      $module_component = $module . ':' . $component;

      // Add a * to the table to denote a component that is overridden and not locked.
      if ($states['locked'] == FALSE && $states['overridden'] == TRUE) {
        $module_component = '* ' . $module_component;
      }

      // If contents of states is empty, replace with a space to avoid possible
      // undefined index in table rendering.
      if (empty($states['locked'])) {
        $states['locked'] = ' ';
      }
      if (empty($states['overridden'])) {
        $states['overridden'] = ' ';
      }

      $row = array(
        'module:component' => $module_component,
        'locked' => $states['locked'],
        'overridden' => $states['overridden'],
      );
      $table[$module_component] = $row;
    }
  }

  drush_print_table($table);

}
