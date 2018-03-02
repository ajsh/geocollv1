<?php
/**
 * @file
 * luggage_seo.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function luggage_seo_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-footer_site-map:sitemap.
  $menu_links['menu-footer_site-map:sitemap'] = array(
    'menu_name' => 'menu-footer',
    'link_path' => 'sitemap',
    'router_path' => 'sitemap',
    'link_title' => 'Site Map',
    'options' => array(
      'attributes' => array(
        'title' => 'Display a site map with RSS feeds.',
      ),
      'identifier' => 'menu-footer_site-map:sitemap',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Site map');

  return $menu_links;
}
