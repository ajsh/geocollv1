<?php
/**
 * @file
 * luggage_contrib.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function luggage_contrib_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'view delete button'.
  $permissions['view delete button'] = array(
    'name' => 'view delete button',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'jammer',
  );

  // Exported permission: 'view submit button'.
  $permissions['view submit button'] = array(
    'name' => 'view submit button',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'jammer',
  );

  return $permissions;
}
