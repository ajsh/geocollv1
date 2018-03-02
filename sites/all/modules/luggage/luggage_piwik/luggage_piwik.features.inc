<?php
/**
 * @file
 * luggage_piwik.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function luggage_piwik_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
