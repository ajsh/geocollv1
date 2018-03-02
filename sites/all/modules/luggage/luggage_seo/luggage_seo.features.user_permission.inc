<?php
/**
 * @file
 * luggage_seo.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function luggage_seo_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access broken links report'.
  $permissions['access broken links report'] = array(
    'name' => 'access broken links report',
    'roles' => array(
      'SEO editor' => 'SEO editor',
      'content editor' => 'content editor',
      'site admin' => 'site admin',
    ),
    'module' => 'linkchecker',
  );

  // Exported permission: 'access own broken links report'.
  $permissions['access own broken links report'] = array(
    'name' => 'access own broken links report',
    'roles' => array(
      'authenticated user' => 'authenticated user',
      'content editor' => 'content editor',
      'site admin' => 'site admin',
    ),
    'module' => 'linkchecker',
  );

  // Exported permission: 'access site map'.
  $permissions['access site map'] = array(
    'name' => 'access site map',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'site_map',
  );

  // Exported permission: 'administer linkchecker'.
  $permissions['administer linkchecker'] = array(
    'name' => 'administer linkchecker',
    'roles' => array(
      'SEO editor' => 'SEO editor',
    ),
    'module' => 'linkchecker',
  );

  // Exported permission: 'administer meta tags'.
  $permissions['administer meta tags'] = array(
    'name' => 'administer meta tags',
    'roles' => array(
      'SEO editor' => 'SEO editor',
    ),
    'module' => 'metatag',
  );

  // Exported permission: 'administer seo_checker configuration'.
  $permissions['administer seo_checker configuration'] = array(
    'name' => 'administer seo_checker configuration',
    'roles' => array(
      'SEO editor' => 'SEO editor',
    ),
    'module' => 'seo_checker',
  );

  // Exported permission: 'administer xmlsitemap'.
  $permissions['administer xmlsitemap'] = array(
    'name' => 'administer xmlsitemap',
    'roles' => array(
      'SEO editor' => 'SEO editor',
    ),
    'module' => 'xmlsitemap',
  );

  // Exported permission: 'allow seo check failures'.
  $permissions['allow seo check failures'] = array(
    'name' => 'allow seo check failures',
    'roles' => array(
      'SEO editor' => 'SEO editor',
      'content editor' => 'content editor',
      'site admin' => 'site admin',
    ),
    'module' => 'seo_checker',
  );

  // Exported permission: 'edit link settings'.
  $permissions['edit link settings'] = array(
    'name' => 'edit link settings',
    'roles' => array(
      'SEO editor' => 'SEO editor',
    ),
    'module' => 'linkchecker',
  );

  // Exported permission: 'edit meta tags'.
  $permissions['edit meta tags'] = array(
    'name' => 'edit meta tags',
    'roles' => array(
      'SEO editor' => 'SEO editor',
    ),
    'module' => 'metatag',
  );

  // Exported permission: 'skip seo checks'.
  $permissions['skip seo checks'] = array(
    'name' => 'skip seo checks',
    'roles' => array(
      'SEO editor' => 'SEO editor',
    ),
    'module' => 'seo_checker',
  );

  return $permissions;
}
