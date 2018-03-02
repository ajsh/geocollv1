<?php
/**
 * @file
 * luggage_announcements.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function luggage_announcements_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu_announcements:announcements
  $menu_links['main-menu_announcements:announcements'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'announcements',
    'router_path' => 'announcements',
    'link_title' => 'Announcements',
    'options' => array(
      'identifier' => 'main-menu_announcements:announcements',
    ),
    'module' => 'system',
    'hidden' => 1,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -42,
    'customized' => 1,
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Announcements');

  return $menu_links;
}
