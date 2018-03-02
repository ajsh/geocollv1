<?php
/**
 * @file
 * luggage_isubit_vars.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function luggage_isubit_vars_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
