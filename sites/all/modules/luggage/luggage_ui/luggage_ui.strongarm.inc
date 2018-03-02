<?php
/**
 * @file
 * luggage_ui.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function luggage_ui_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'views_ui_show_advanced_help_warning';
  $strongarm->value = 0;
  $export['views_ui_show_advanced_help_warning'] = $strongarm;

  return $export;
}
