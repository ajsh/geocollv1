<?php
/**
 * @file
 * luggage_biblio.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function luggage_biblio_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'biblio_annotations';
  $strongarm->value = 'none';
  $export['biblio_annotations'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'biblio_author_links';
  $strongarm->value = 1;
  $export['biblio_author_links'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'biblio_author_link_profile';
  $strongarm->value = 0;
  $export['biblio_author_link_profile'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'biblio_author_link_profile_path';
  $strongarm->value = 'user/[user:uid]';
  $export['biblio_author_link_profile_path'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'biblio_auto_citekey';
  $strongarm->value = 1;
  $export['biblio_auto_citekey'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'biblio_auto_orphaned_author_delete';
  $strongarm->value = 1;
  $export['biblio_auto_orphaned_author_delete'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'biblio_base';
  $strongarm->value = 'publications';
  $export['biblio_base'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'biblio_baseopenurl';
  $strongarm->value = '';
  $export['biblio_baseopenurl'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'biblio_base_title';
  $strongarm->value = 'Publications';
  $export['biblio_base_title'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'biblio_button_hide';
  $strongarm->value = 1;
  $export['biblio_button_hide'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'biblio_citekey_field1';
  $strongarm->value = 'nid';
  $export['biblio_citekey_field1'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'biblio_citekey_field2';
  $strongarm->value = 'nid';
  $export['biblio_citekey_field2'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'biblio_citekey_phpcode';
  $strongarm->value = '';
  $export['biblio_citekey_phpcode'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'biblio_citekey_prefix';
  $strongarm->value = '';
  $export['biblio_citekey_prefix'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'biblio_contrib_fields_delta';
  $strongarm->value = '2';
  $export['biblio_contrib_fields_delta'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'biblio_copy_taxo_terms_to_keywords';
  $strongarm->value = 0;
  $export['biblio_copy_taxo_terms_to_keywords'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'biblio_display_citation_key';
  $strongarm->value = 0;
  $export['biblio_display_citation_key'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'biblio_download_links_to_node';
  $strongarm->value = 0;
  $export['biblio_download_links_to_node'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'biblio_export_links';
  $strongarm->value = array(
    'xml' => 'xml',
    'tagged' => 0,
  );
  $export['biblio_export_links'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'biblio_file_link_type';
  $strongarm->value = 'text';
  $export['biblio_file_link_type'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'biblio_fix_isi_links';
  $strongarm->value = 0;
  $export['biblio_fix_isi_links'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'biblio_footnotes_integration';
  $strongarm->value = 0;
  $export['biblio_footnotes_integration'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'biblio_hide_bibtex_braces';
  $strongarm->value = 0;
  $export['biblio_hide_bibtex_braces'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'biblio_hide_other_fields';
  $strongarm->value = 0;
  $export['biblio_hide_other_fields'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'biblio_index';
  $strongarm->value = 1;
  $export['biblio_index'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'biblio_init_auth_count';
  $strongarm->value = '6';
  $export['biblio_init_auth_count'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'biblio_inpress_year_text';
  $strongarm->value = 'In Press';
  $export['biblio_inpress_year_text'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'biblio_isi_url';
  $strongarm->value = 'http://apps.isiknowledge.com/InboundService.do?Func=Frame&product=WOS&action=retrieve&SrcApp=EndNote&Init=Yes&SrcAuth=ResearchSoft&mode=FullRecord&UT=';
  $export['biblio_isi_url'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'biblio_keyword_freetagging';
  $strongarm->value = 1;
  $export['biblio_keyword_freetagging'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'biblio_keyword_orphan_autoclean';
  $strongarm->value = 1;
  $export['biblio_keyword_orphan_autoclean'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'biblio_keyword_sep';
  $strongarm->value = ',';
  $export['biblio_keyword_sep'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'biblio_keyword_vocabulary';
  $strongarm->value = '3';
  $export['biblio_keyword_vocabulary'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'biblio_links_target_new_window';
  $strongarm->value = 0;
  $export['biblio_links_target_new_window'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'biblio_link_title_url';
  $strongarm->value = 0;
  $export['biblio_link_title_url'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'biblio_lookup_links';
  $strongarm->value = array(
    'crossref' => 'crossref',
    'google' => 'google',
  );
  $export['biblio_lookup_links'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'biblio_max_user_tid';
  $strongarm->value = 1000;
  $export['biblio_max_user_tid'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'biblio_node_layout';
  $strongarm->value = 'orig';
  $export['biblio_node_layout'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'biblio_no_year_text';
  $strongarm->value = 'Submitted';
  $export['biblio_no_year_text'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'biblio_openurlimage';
  $strongarm->value = '';
  $export['biblio_openurlimage'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'biblio_openurl_sid';
  $strongarm->value = '';
  $export['biblio_openurl_sid'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'biblio_order';
  $strongarm->value = 'DESC';
  $export['biblio_order'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'biblio_orphan_clean_interval';
  $strongarm->value = '604800';
  $export['biblio_orphan_clean_interval'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'biblio_rowsperpage';
  $strongarm->value = '50';
  $export['biblio_rowsperpage'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'biblio_rss';
  $strongarm->value = 0;
  $export['biblio_rss'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'biblio_rss_number_of_entries';
  $strongarm->value = '10';
  $export['biblio_rss_number_of_entries'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'biblio_search';
  $strongarm->value = 1;
  $export['biblio_search'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'biblio_search_button_text';
  $strongarm->value = 'Search Pubs';
  $export['biblio_search_button_text'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'biblio_show_crossref_profile_form';
  $strongarm->value = 0;
  $export['biblio_show_crossref_profile_form'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'biblio_show_openurl_profile_form';
  $strongarm->value = 0;
  $export['biblio_show_openurl_profile_form'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'biblio_show_profile';
  $strongarm->value = 0;
  $export['biblio_show_profile'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'biblio_show_user_profile_form';
  $strongarm->value = 0;
  $export['biblio_show_user_profile_form'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'biblio_sort';
  $strongarm->value = 'year';
  $export['biblio_sort'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'biblio_sort_tabs';
  $strongarm->value = array(
    'author' => 'author',
    'title' => 'title',
    'type' => 'type',
    'year' => 'year',
    'keyword' => 0,
  );
  $export['biblio_sort_tabs'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'biblio_sort_tabs_style';
  $strongarm->value = 1;
  $export['biblio_sort_tabs_style'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'biblio_stop_words';
  $strongarm->value = 'a,an,is,on,the';
  $export['biblio_stop_words'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'biblio_style';
  $strongarm->value = 'cse';
  $export['biblio_style'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'biblio_user_style';
  $strongarm->value = 'system';
  $export['biblio_user_style'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'biblio_view_only_own';
  $strongarm->value = 0;
  $export['biblio_view_only_own'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_biblio';
  $strongarm->value = '1';
  $export['comment_biblio'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_biblio';
  $strongarm->value = 0;
  $export['node_submitted_biblio'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'publishcontent_biblio';
  $strongarm->value = 1;
  $export['publishcontent_biblio'] = $strongarm;

  return $export;
}
