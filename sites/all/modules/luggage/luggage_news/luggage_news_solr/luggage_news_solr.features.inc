<?php
/**
 * @file
 * luggage_news_solr.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function luggage_news_solr_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "facetapi" && $api == "facetapi_defaults") {
    return array("version" => "1");
  }
}
