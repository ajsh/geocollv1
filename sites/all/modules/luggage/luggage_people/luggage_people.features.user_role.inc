<?php
/**
 * @file
 * luggage_people.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function luggage_people_user_default_roles() {
  $roles = array();

  // Exported role: people editor.
  $roles['people editor'] = array(
    'name' => 'people editor',
    'weight' => 3,
  );

  return $roles;
}
