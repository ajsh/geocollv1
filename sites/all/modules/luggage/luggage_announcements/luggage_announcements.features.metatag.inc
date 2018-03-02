<?php
/**
 * @file
 * luggage_announcements.features.metatag.inc
 */

/**
 * Implements hook_metatag_export_default().
 */
function luggage_announcements_metatag_export_default() {
  $config = array();

  // Exported Metatag config instance: node:announcement.
  $config['node:announcement'] = array(
    'instance' => 'node:announcement',
    'config' => array(
      'description' => array(
        'value' => '[node:field-announcement-body:summary]',
      ),
    ),
  );

  return $config;
}
