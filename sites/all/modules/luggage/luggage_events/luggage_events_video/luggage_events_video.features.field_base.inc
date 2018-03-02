<?php
/**
 * @file
 * luggage_events_video.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function luggage_events_video_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_event_transcript'.
  $field_bases['field_event_transcript'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_event_transcript',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'text_long',
  );

  return $field_bases;
}
