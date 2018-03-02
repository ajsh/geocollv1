<?php
/**
 * @file
 * luggage_ui.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function luggage_ui_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
