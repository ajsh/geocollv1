<?php
/**
 * @file
 * luggage_roles.ds.inc
 */

/**
 * Implements hook_ds_view_modes_info().
 */
function luggage_roles_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'frontpanel';
  $ds_view_mode->label = 'Frontpanel';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['frontpanel'] = $ds_view_mode;

  return $export;
}
