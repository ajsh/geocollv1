<?php
/**
 * @file
 * luggage_people.features.metatag.inc
 */

/**
 * Implements hook_metatag_export_default().
 */
function luggage_people_metatag_export_default() {
  $config = array();

  // Exported Metatag config instance: node:people.
  $config['node:people'] = array(
    'instance' => 'node:people',
    'config' => array(
      'description' => array(
        'value' => '[node:field-people-bio:value]',
      ),
    ),
  );

  return $config;
}
