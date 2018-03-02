<?php
/**
 * @file
 * luggage_ckeditor.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function luggage_ckeditor_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
