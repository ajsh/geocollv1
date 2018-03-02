<?php
/**
 * @file
 * luggage_isushib.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function luggage_isushib_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer shibboleth future roles'.
  $permissions['administer shibboleth future roles'] = array(
    'name' => 'administer shibboleth future roles',
    'roles' => array(
      'shibboleth user admin' => 'shibboleth user admin',
    ),
    'module' => 'isushibsiteaccess',
  );

  // Exported permission: 'administer shibboleth site access'.
  $permissions['administer shibboleth site access'] = array(
    'name' => 'administer shibboleth site access',
    'roles' => array(
      'shibboleth user admin' => 'shibboleth user admin',
    ),
    'module' => 'isushibsiteaccess',
  );

  return $permissions;
}
