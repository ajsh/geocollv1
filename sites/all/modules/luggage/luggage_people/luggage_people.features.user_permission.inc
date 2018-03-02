<?php
/**
 * @file
 * luggage_people.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function luggage_people_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create people content'.
  $permissions['create people content'] = array(
    'name' => 'create people content',
    'roles' => array(
      'people editor' => 'people editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any people content'.
  $permissions['delete any people content'] = array(
    'name' => 'delete any people content',
    'roles' => array(
      'people editor' => 'people editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own people content'.
  $permissions['delete own people content'] = array(
    'name' => 'delete own people content',
    'roles' => array(
      'people editor' => 'people editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any people content'.
  $permissions['edit any people content'] = array(
    'name' => 'edit any people content',
    'roles' => array(
      'people editor' => 'people editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own people content'.
  $permissions['edit own people content'] = array(
    'name' => 'edit own people content',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  return $permissions;
}
