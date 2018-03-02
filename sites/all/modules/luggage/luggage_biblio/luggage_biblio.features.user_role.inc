<?php
/**
 * @file
 * luggage_biblio.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function luggage_biblio_user_default_roles() {
  $roles = array();

  // Exported role: biblio editor.
  $roles['biblio editor'] = array(
    'name' => 'biblio editor',
    'weight' => 10,
  );

  return $roles;
}
