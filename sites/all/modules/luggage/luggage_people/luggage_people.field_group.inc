<?php
/**
 * @file
 * luggage_people.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function luggage_people_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_contact|node|people|full';
  $field_group->group_name = 'group_contact';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'people';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Contact',
    'weight' => '11',
    'children' => array(
      0 => 'field_people_city',
      1 => 'field_people_email',
      2 => 'field_people_phone',
      3 => 'field_people_postal',
      4 => 'field_people_state',
      5 => 'field_people_street',
      6 => 'field_people_website',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Contact',
      'instance_settings' => array(
        'classes' => 'group-contact field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_contact|node|people|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_people_affiliated|node|people|form';
  $field_group->group_name = 'group_people_affiliated';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'people';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Non-ISU People Fields',
    'weight' => '18',
    'children' => array(
      0 => 'field_people_affiliation',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_people_affiliated|node|people|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_people_faculty|node|people|form';
  $field_group->group_name = 'group_people_faculty';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'people';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Faculty Fields',
    'weight' => '17',
    'children' => array(
      0 => 'field_people_teaching',
      1 => 'field_people_interdepartmental',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_people_faculty|node|people|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_people_location|node|people|form';
  $field_group->group_name = 'group_people_location';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'people';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Location Fields',
    'weight' => '15',
    'children' => array(
      0 => 'field_people_city',
      1 => 'field_people_email',
      2 => 'field_people_phone',
      3 => 'field_people_postal',
      4 => 'field_people_state',
      5 => 'field_people_street',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_people_location|node|people|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_people_student|node|people|form';
  $field_group->group_name = 'group_people_student';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'people';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Student Fields',
    'weight' => '16',
    'children' => array(
      0 => 'field_people_advisor',
      1 => 'field_people_major',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_people_student|node|people|form'] = $field_group;

  return $export;
}
