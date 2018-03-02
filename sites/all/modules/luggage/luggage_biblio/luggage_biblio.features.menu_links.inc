<?php
/**
 * @file
 * luggage_biblio.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function luggage_biblio_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu_publications:publications.
  $menu_links['main-menu_publications:publications'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'publications',
    'router_path' => 'publications',
    'link_title' => 'Publications',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'identifier' => 'main-menu_publications:publications',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Publications');

  return $menu_links;
}
