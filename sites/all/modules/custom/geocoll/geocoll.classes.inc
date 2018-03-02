<?php

require_once DRUPAL_ROOT . '/includes/entity.inc';

/**
 * C'mon it's time to get hyped say OOP there it is
 */

class DrupalNode extends stdClass {

  public function __construct($type, $arguments) { 

    $node = (object) array_shift($arguments); //$node will be assigned the first element from $arguments array. (Removed from $args.. array)

    if (empty($node->nid)) {
      $this->language = LANGUAGE_NONE;
      $this->uid = 1;
      $this->created = REQUEST_TIME;
      $this->changed = REQUEST_TIME;
      $this->status = 1;
      $this->comment = 0;
      $this->promote = 0;
      $this->moderate = 0;
      $this->sticky = 0;
      $this->title = $type . ' node';
      $this->type = $type;
    }

    foreach ($node as $key => $value) {
      $this->$key = $value;
    }

  }

  public static function factory($argument) {
    return new static($argument);                 //ask what new static() does?
  }

  public function save() {
    $this->validated = TRUE;
    node_save($this);
    if (!isset($this->nid)) {
      throw new GeocollDataEntryException(sprintf('Error creating a new %s record', $this->type));
    }
    return $this->nid;
  }

  /**
   * translates Y, N to boolean
   */
  protected static function yn_to_bool($field) {
    if (strtolower($field) === 'y') {
      $bool_out = 1;
    }
    elseif (strtolower($field) === 'n') {
      $bool_out = 0;
    }
    else {
      $bool_out = NULL;
    }
    return $bool_out;
  }


  /**
   * translates TRUE,FALSE text to boolean
   */
  protected static function tf_to_bool($field) {
    if (strtolower($field) === 'true') {
      $bool_out = 1;
    }
    elseif (strtolower($field) === 'false') {
      $bool_out = 0;
    }
    else {
      $bool_out = NULL;
    }
    return $bool_out;
  }

  /**
   * Lookup taxonomy term, if not exist, make it
   * either way, return tid -- Taxonomy ID
   */
  protected static function save_taxonomy_term($term, $vocabulary) {

    $vocabularies = taxonomy_vocabulary_get_names();

    $terms = taxonomy_get_term_by_name($term, $vocabulary);

    if (empty($terms)) {
      //make a new term for this vocab
      $newTerm = new stdClass();
      $newTerm->name = $term;
      $newTerm->vid = $vocabularies[$vocabulary]->vid;
      taxonomy_term_save($newTerm);
      return $newTerm->tid;
    }
    else {
      //term already exists, hope there is only one, b/c I'm not handling multiple well
      return key($terms);
    }

  }

  /**
   * translates null and NA text to NULL type
   */
  protected static function handle_null($field) {
    if (strtolower($field) === 'na' || strtolower($field) === 'null' || $field === '') {
      $field_out = NULL;
    }
    else {
      $field_out = $field;
    }
    return $field_out;
  }

}


class collection_item extends DrupalNode {
  public function __construct() {
    parent::__construct('collection_item', func_get_args()); //Previously dynamic
  }

private static function convert_coll_date($row) {
    if (strtolower($row['Collection_Date']) != NULL ) {
      $date = $row['Collection_Date'];
      $date = date('Y-M-d H:i:s', strtotime($date));
      return $date;
    }
    else {
      return NULL;
    }
  }
  
  public static function createFromCSV($row) {
    $properties = array();
    $properties['field_collitem_page'][LANGUAGE_NONE][0]['value'] = DrupalNode::handle_null($row['Page']);
    $properties['field_collitem_id_1'][LANGUAGE_NONE][0]['value'] = DrupalNode::handle_null($row['ID-1']);
    $properties['field_collitem_id_2'][LANGUAGE_NONE][0]['value'] = DrupalNode::handle_null($row['ID-2']);
    $properties['field_coll_thinsection_present	'][LANGUAGE_NONE][0]['value'] = DrupalNode::tf_to_bool($row['Thinsection_Present']);
    $properties['field_collitem_mineralogy'][LANGUAGE_NONE][0]['tid'] = DrupalNode::save_taxonomy_term($row['Mineralogy'], 'mineralogy'); 
    $properties['field_collitem_allochems'][LANGUAGE_NONE][0]['tid'] = DrupalNode::save_taxonomy_term($row['Allochems'], 'allochems'); 
    $properties['field_collitem_fossils'][LANGUAGE_NONE][0]['tid'] = DrupalNode::save_taxonomy_term($row['Fossils'], 'fossils');
    $properties['field_collitem_carb_dunham'][LANGUAGE_NONE][0]['tid'] = DrupalNode::save_taxonomy_term($row['Carb_Dunham'], 'carb_dunham');
    $properties['field_collitem_carb_folk'][LANGUAGE_NONE][0]['tid'] = DrupalNode::save_taxonomy_term($row['Carb_Folk'], 'carb_folk');
    $properties['field_porosity'][LANGUAGE_NONE][0]['tid'] = DrupalNode::save_taxonomy_term($row['Porosity'], 'porosity');
    $properties['field_collitem_notes_diag'][LANGUAGE_NONE][0]['value'] = DrupalNode::handle_null($row['Notes_Diag']);
    $properties['field_collitem_notes'][LANGUAGE_NONE][0]['value'] = DrupalNode::handle_null($row['Notes']);
    $properties['field_collitem_defects'][LANGUAGE_NONE][0]['value'] = DrupalNode::handle_null($row['Defects']);
    $properties['field_collitem_age'][LANGUAGE_NONE][0]['tid'] = DrupalNode::save_taxonomy_term($row['Age'], 'age');
    $properties['field_collitem_bed'][LANGUAGE_NONE][0]['value'] = DrupalNode::handle_null($row['Bed']);
    $properties['field_collitem_formation'][LANGUAGE_NONE][0]['tid'] = DrupalNode::save_taxonomy_term($row['Formation'], 'formation');
    $properties['field_collitem_site'][LANGUAGE_NONE][0]['value'] = DrupalNode::handle_null($row['Site']);
    $properties['field_collitem_township'][LANGUAGE_NONE][0]['tid'] = DrupalNode::save_taxonomy_term($row['Township'], 'township');
    $properties['field_collitem_range'][LANGUAGE_NONE][0]['tid'] = DrupalNode::save_taxonomy_term($row['Range'], 'range');
    $properties['field_section'][LANGUAGE_NONE][0]['tid'] = DrupalNode::save_taxonomy_term($row['Section'], 'section');
    $properties['field_collitem_qq'][LANGUAGE_NONE][0]['tid'] = DrupalNode::save_taxonomy_term($row['QQ'], 'qq');
    $properties['field_collitem_city'][LANGUAGE_NONE][0]['tid'] = DrupalNode::save_taxonomy_term($row['City'], 'city');
    $properties['field_collitem_county'][LANGUAGE_NONE][0]['tid'] = DrupalNode::save_taxonomy_term($row['County'], 'county');
    $properties['field_collitem_state'][LANGUAGE_NONE][0]['tid'] = DrupalNode::save_taxonomy_term($row['State'], 'state');
    $properties['field_collitem_country'][LANGUAGE_NONE][0]['tid'] = DrupalNode::save_taxonomy_term($row['Country'], 'country');
    $properties['field_collitem_collector'][LANGUAGE_NONE][0]['tid'] = DrupalNode::save_taxonomy_term($row['Collector'], 'collector');
    
    
    $properties['field_collitem_collection_date	'][LANGUAGE_NONE][0]['value'] = DrupalNode::convert_coll_date($row['Collection_Date']);


    $properties['field_lithology_german_archaid_'][LANGUAGE_NONE][0]['value'] = DrupalNode::handle_null($row['Lithology (German Archaid)']);
    $properties['field_lithology_eng_translation'][LANGUAGE_NONE][0]['value'] = DrupalNode::handle_null($row['Lithology (English Translation)']);
    $properties['field_lithology_eng_modern_name'][LANGUAGE_NONE][0]['value'] = DrupalNode::handle_null($row['Lithology (English Modern Name)']);
    
    $properties['field_dynamic_plasma'][LANGUAGE_NONE][0]['value'] = DrupalNode::yn_to_bool($row['Plasma']);

    return new collection_item($properties);
  }
}


/**
 * GeocollDataEntryException class.
 */
 
class GeocollDataEntryException extends Exception {}

/**
 * GeocollDataEntityFieldQuery class.
 */
class GeocollDataEntityFieldQuery extends EntityFieldQuery {

  public $fieldNullConditions = array();

  public $fieldFalseOrNullConditions = array();

  public function __construct() {
    $this->entityCondition('entity_type', 'node');
    $this->propertyCondition('status', 1);
    //$this->addMetaData('account', user_load(1));
    $this->addTag('DANGEROUS_ACCESS_CHECK_OPT_OUT');
    $this->propertyOrderBy('nid', 'ASC');
  }

  public function fieldNullCondition($field_name, $column) {
    $this->fieldNullConditions[$field_name] = $column;
  }

  public function fieldFalseOrNullCondition($field_name, $column) {
    $this->fieldFalseOrNullConditions[$field_name] = $column;
  }

  public function finishQuery($select_query, $id_key = 'entity_id') {

    foreach ($this->fieldNullConditions as $field_name => $column) {
      $table_alias = $select_query->leftJoin('field_data_' . $field_name, NULL, 'node.nid = %alias.entity_id');
      $field_key = $table_alias . '.' . $field_name . '_' . $column;
      $select_query->isNull($field_key);
    }

    foreach ($this->fieldFalseOrNullConditions as $field_name => $column) {
      $table_alias = $select_query->leftJoin('field_data_' . $field_name, NULL, 'node.nid = %alias.entity_id');
      $field_key = $table_alias . '.' . $field_name . '_' . $column;
      $select_query->condition(db_or()->condition($field_key, 0, '=')->isNull($field_key));
    }

    return parent::finishQuery($select_query, $id_key);
  }

}
