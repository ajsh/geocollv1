<?php
/**
 * @file
 * luggage_isubit_solr.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function luggage_isubit_solr_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'apachesolr_default_environment';
  $strongarm->value = 'solr';
  $export['apachesolr_default_environment'] = $strongarm;

  return $export;
}
