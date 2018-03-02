<?php
/**
 * @file
 * luggage_roles.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function luggage_roles_user_default_roles() {
  $roles = array();

  // Exported role: content editor.
  $roles['content editor'] = array(
    'name' => 'content editor',
    'weight' => 2,
  );

  // Exported role: site admin.
  $roles['site admin'] = array(
    'name' => 'site admin',
    'weight' => 6,
  );

  // Exported role: taxonomy editor.
  $roles['taxonomy editor'] = array(
    'name' => 'taxonomy editor',
    'weight' => 4,
  );

  return $roles;
}
