<?php
/**
 * @file
 * luggage_isushib.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function luggage_isushib_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
