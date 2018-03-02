<?php
/**
 * @file
 * luggage_announcements.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function luggage_announcements_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "flexslider" && $api == "flexslider_default_preset") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function luggage_announcements_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function luggage_announcements_image_default_styles() {
  $styles = array();

  // Exported image style: announcement_full.
  $styles['announcement_full'] = array(
    'label' => 'announcement_full',
    'effects' => array(
      5 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 1180,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
      6 => array(
        'name' => 'image_crop',
        'data' => array(
          'width' => 1180,
          'height' => 346,
          'anchor' => 'center-center',
        ),
        'weight' => 2,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function luggage_announcements_node_info() {
  $items = array(
    'announcement' => array(
      'name' => t('Announcement Banner'),
      'base' => 'node_content',
      'description' => t('Prominently feature important announcements as a banner image and a link to more details.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
