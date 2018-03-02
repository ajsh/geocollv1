<?php
/**
 * @file
 * luggage_roles.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function luggage_roles_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu_:categories.
  $menu_links['main-menu_:categories'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'categories',
    'router_path' => 'categories',
    'link_title' => '≡',
    'options' => array(
      'identifier' => 'main-menu_:categories',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('≡');

  return $menu_links;
}
