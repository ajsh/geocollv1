<?php
/**
 * @file
 * luggage_isushib.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function luggage_isushib_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'isushib_domain';
  $strongarm->value = 'iastate.edu';
  $export['isushib_domain'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'isushib_id_is_email';
  $strongarm->value = 1;
  $export['isushib_id_is_email'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'isushib_ldap_basedn';
  $strongarm->value = 'dc=iastate,dc=edu';
  $export['isushib_ldap_basedn'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'isushib_ldap_searchfield';
  $strongarm->value = '(|(uid=%username))';
  $export['isushib_ldap_searchfield'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'isushib_ldap_server';
  $strongarm->value = 'ldap.iastate.edu';
  $export['isushib_ldap_server'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'isushib_ldap_usernamefield';
  $strongarm->value = '';
  $export['isushib_ldap_usernamefield'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'isushib_login_dir';
  $strongarm->value = 'shibboleth';
  $export['isushib_login_dir'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'isushib_success_url';
  $strongarm->value = '';
  $export['isushib_success_url'] = $strongarm;

  return $export;
}
