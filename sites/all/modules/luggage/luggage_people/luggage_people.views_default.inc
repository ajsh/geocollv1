<?php
/**
 * @file
 * luggage_people.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function luggage_people_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'people';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'people';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'People';
  $handler->display->display_options['css_class'] = 'luggage-grid';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_people_category',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['row_class'] = 'luggage-gridrow';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Content: Taxonomy terms on node */
  $handler->display->display_options['relationships']['term_node_tid']['id'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['table'] = 'node';
  $handler->display->display_options['relationships']['term_node_tid']['field'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['required'] = TRUE;
  $handler->display->display_options['relationships']['term_node_tid']['vocabularies'] = array(
    'people_category' => 'people_category',
    'keywords' => 0,
    'tags' => 0,
  );
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Profile Picture */
  $handler->display->display_options['fields']['field_people_image']['id'] = 'field_people_image';
  $handler->display->display_options['fields']['field_people_image']['table'] = 'field_data_field_people_image';
  $handler->display->display_options['fields']['field_people_image']['field'] = 'field_people_image';
  $handler->display->display_options['fields']['field_people_image']['label'] = '';
  $handler->display->display_options['fields']['field_people_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_people_image']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_people_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_people_image']['settings'] = array(
    'image_style' => 'people_thumb',
    'image_link' => 'content',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['title']['element_wrapper_class'] = 'profile-title h2';
  /* Field: Content: Position */
  $handler->display->display_options['fields']['field_people_position']['id'] = 'field_people_position';
  $handler->display->display_options['fields']['field_people_position']['table'] = 'field_data_field_people_position';
  $handler->display->display_options['fields']['field_people_position']['field'] = 'field_people_position';
  $handler->display->display_options['fields']['field_people_position']['label'] = '';
  $handler->display->display_options['fields']['field_people_position']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_people_position']['delta_offset'] = '0';
  /* Field: Content: People Category */
  $handler->display->display_options['fields']['field_people_category']['id'] = 'field_people_category';
  $handler->display->display_options['fields']['field_people_category']['table'] = 'field_data_field_people_category';
  $handler->display->display_options['fields']['field_people_category']['field'] = 'field_people_category';
  $handler->display->display_options['fields']['field_people_category']['label'] = '';
  $handler->display->display_options['fields']['field_people_category']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_people_category']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_people_category']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_people_category']['element_wrapper_class'] = 'profile-category';
  $handler->display->display_options['fields']['field_people_category']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_people_category']['delta_offset'] = '0';
  /* Sort criterion: Taxonomy term: Weight */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  $handler->display->display_options['sorts']['weight']['relationship'] = 'term_node_tid';
  /* Sort criterion: Content: Last Name (field_people_last_name) */
  $handler->display->display_options['sorts']['field_people_last_name_value']['id'] = 'field_people_last_name_value';
  $handler->display->display_options['sorts']['field_people_last_name_value']['table'] = 'field_data_field_people_last_name';
  $handler->display->display_options['sorts']['field_people_last_name_value']['field'] = 'field_people_last_name_value';
  /* Contextual filter: Content: Has taxonomy term ID */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_index';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'taxonomy_tid';
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['tid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['tid']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['tid']['validate_options']['vocabularies'] = array(
    'people_category' => 'people_category',
  );
  $handler->display->display_options['arguments']['tid']['validate_options']['type'] = 'tids';
  $handler->display->display_options['arguments']['tid']['validate_options']['transform'] = TRUE;
  $handler->display->display_options['arguments']['tid']['break_phrase'] = TRUE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'people' => 'people',
  );

  /* Display: People */
  $handler = $view->new_display('page', 'People', 'people');
  $handler->display->display_options['enabled'] = FALSE;
  $handler->display->display_options['display_description'] = 'default';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['title']['element_wrapper_class'] = 'profile-title h2';
  /* Field: Content: Profile Picture */
  $handler->display->display_options['fields']['field_people_image']['id'] = 'field_people_image';
  $handler->display->display_options['fields']['field_people_image']['table'] = 'field_data_field_people_image';
  $handler->display->display_options['fields']['field_people_image']['field'] = 'field_people_image';
  $handler->display->display_options['fields']['field_people_image']['label'] = '';
  $handler->display->display_options['fields']['field_people_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_people_image']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_people_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_people_image']['settings'] = array(
    'image_style' => 'people_thumb',
    'image_link' => 'content',
  );
  /* Field: Content: Position */
  $handler->display->display_options['fields']['field_people_position']['id'] = 'field_people_position';
  $handler->display->display_options['fields']['field_people_position']['table'] = 'field_data_field_people_position';
  $handler->display->display_options['fields']['field_people_position']['field'] = 'field_people_position';
  $handler->display->display_options['fields']['field_people_position']['label'] = '';
  $handler->display->display_options['fields']['field_people_position']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_people_position']['delta_offset'] = '0';
  /* Field: Content: Biography */
  $handler->display->display_options['fields']['field_people_bio']['id'] = 'field_people_bio';
  $handler->display->display_options['fields']['field_people_bio']['table'] = 'field_data_field_people_bio';
  $handler->display->display_options['fields']['field_people_bio']['field'] = 'field_people_bio';
  $handler->display->display_options['fields']['field_people_bio']['label'] = '';
  $handler->display->display_options['fields']['field_people_bio']['element_label_colon'] = FALSE;
  /* Field: Content: Website */
  $handler->display->display_options['fields']['field_people_website']['id'] = 'field_people_website';
  $handler->display->display_options['fields']['field_people_website']['table'] = 'field_data_field_people_website';
  $handler->display->display_options['fields']['field_people_website']['field'] = 'field_people_website';
  $handler->display->display_options['fields']['field_people_website']['label'] = '';
  $handler->display->display_options['fields']['field_people_website']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_people_website']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_people_website']['delta_limit'] = '3';
  $handler->display->display_options['fields']['field_people_website']['delta_offset'] = '0';
  /* Field: Content: People Category */
  $handler->display->display_options['fields']['field_people_category']['id'] = 'field_people_category';
  $handler->display->display_options['fields']['field_people_category']['table'] = 'field_data_field_people_category';
  $handler->display->display_options['fields']['field_people_category']['field'] = 'field_people_category';
  $handler->display->display_options['fields']['field_people_category']['label'] = '';
  $handler->display->display_options['fields']['field_people_category']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_people_category']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_people_category']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_people_category']['element_wrapper_class'] = 'profile-category';
  $handler->display->display_options['fields']['field_people_category']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_people_category']['delta_offset'] = '0';
  /* Field: Content: Email */
  $handler->display->display_options['fields']['field_people_email']['id'] = 'field_people_email';
  $handler->display->display_options['fields']['field_people_email']['table'] = 'field_data_field_people_email';
  $handler->display->display_options['fields']['field_people_email']['field'] = 'field_people_email';
  $handler->display->display_options['fields']['field_people_email']['label'] = '';
  $handler->display->display_options['fields']['field_people_email']['element_label_colon'] = FALSE;
  $handler->display->display_options['path'] = 'people';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'People';
  $handler->display->display_options['menu']['name'] = 'main-menu';

  /* Display: People Grid */
  $handler = $view->new_display('page', 'People Grid', 'people_grid');
  $handler->display->display_options['display_description'] = 'People displayed in a grid';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'name',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['row_class'] = 'luggage-gridrow';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: First Name */
  $handler->display->display_options['fields']['field_people_first_name']['id'] = 'field_people_first_name';
  $handler->display->display_options['fields']['field_people_first_name']['table'] = 'field_data_field_people_first_name';
  $handler->display->display_options['fields']['field_people_first_name']['field'] = 'field_people_first_name';
  $handler->display->display_options['fields']['field_people_first_name']['label'] = '';
  $handler->display->display_options['fields']['field_people_first_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_people_first_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_people_first_name']['type'] = 'text_plain';
  /* Field: Content: Middle Initial */
  $handler->display->display_options['fields']['field_people_middle_initial']['id'] = 'field_people_middle_initial';
  $handler->display->display_options['fields']['field_people_middle_initial']['table'] = 'field_data_field_people_middle_initial';
  $handler->display->display_options['fields']['field_people_middle_initial']['field'] = 'field_people_middle_initial';
  $handler->display->display_options['fields']['field_people_middle_initial']['label'] = '';
  $handler->display->display_options['fields']['field_people_middle_initial']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_people_middle_initial']['element_label_colon'] = FALSE;
  /* Field: Content: Last Name */
  $handler->display->display_options['fields']['field_people_last_name']['id'] = 'field_people_last_name';
  $handler->display->display_options['fields']['field_people_last_name']['table'] = 'field_data_field_people_last_name';
  $handler->display->display_options['fields']['field_people_last_name']['field'] = 'field_people_last_name';
  $handler->display->display_options['fields']['field_people_last_name']['label'] = '';
  $handler->display->display_options['fields']['field_people_last_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_people_last_name']['element_label_colon'] = FALSE;
  /* Field: Content: Profile Picture */
  $handler->display->display_options['fields']['field_people_image']['id'] = 'field_people_image';
  $handler->display->display_options['fields']['field_people_image']['table'] = 'field_data_field_people_image';
  $handler->display->display_options['fields']['field_people_image']['field'] = 'field_people_image';
  $handler->display->display_options['fields']['field_people_image']['label'] = '';
  $handler->display->display_options['fields']['field_people_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_people_image']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_people_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_people_image']['settings'] = array(
    'image_style' => 'people_thumb',
    'image_link' => 'content',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '[field_people_first_name] [field_people_middle_initial] [field_people_last_name]';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['title']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['title']['element_wrapper_class'] = 'profile-title h2';
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Position */
  $handler->display->display_options['fields']['field_people_position']['id'] = 'field_people_position';
  $handler->display->display_options['fields']['field_people_position']['table'] = 'field_data_field_people_position';
  $handler->display->display_options['fields']['field_people_position']['field'] = 'field_people_position';
  $handler->display->display_options['fields']['field_people_position']['label'] = '';
  $handler->display->display_options['fields']['field_people_position']['element_class'] = 'luggage-gridgreen';
  $handler->display->display_options['fields']['field_people_position']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_people_position']['delta_offset'] = '0';
  /* Field: Content: People Category */
  $handler->display->display_options['fields']['field_people_category']['id'] = 'field_people_category';
  $handler->display->display_options['fields']['field_people_category']['table'] = 'field_data_field_people_category';
  $handler->display->display_options['fields']['field_people_category']['field'] = 'field_people_category';
  $handler->display->display_options['fields']['field_people_category']['label'] = '';
  $handler->display->display_options['fields']['field_people_category']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_people_category']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_people_category']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_people_category']['element_wrapper_class'] = 'profile-category';
  $handler->display->display_options['fields']['field_people_category']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_people_category']['delta_offset'] = '0';
  /* Field: Content: Area of Expertise */
  $handler->display->display_options['fields']['field_people_expertise']['id'] = 'field_people_expertise';
  $handler->display->display_options['fields']['field_people_expertise']['table'] = 'field_data_field_people_expertise';
  $handler->display->display_options['fields']['field_people_expertise']['field'] = 'field_people_expertise';
  $handler->display->display_options['fields']['field_people_expertise']['label'] = '';
  $handler->display->display_options['fields']['field_people_expertise']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_people_expertise']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_people_expertise']['delta_offset'] = '0';
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'term_node_tid';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Taxonomy term: Weight */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  $handler->display->display_options['sorts']['weight']['relationship'] = 'term_node_tid';
  /* Sort criterion: Content: Sticky */
  $handler->display->display_options['sorts']['sticky']['id'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['table'] = 'node';
  $handler->display->display_options['sorts']['sticky']['field'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['order'] = 'DESC';
  /* Sort criterion: Content: Last Name (field_people_last_name) */
  $handler->display->display_options['sorts']['field_people_last_name_value']['id'] = 'field_people_last_name_value';
  $handler->display->display_options['sorts']['field_people_last_name_value']['table'] = 'field_data_field_people_last_name';
  $handler->display->display_options['sorts']['field_people_last_name_value']['field'] = 'field_people_last_name_value';
  $handler->display->display_options['path'] = 'people';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'People';
  $handler->display->display_options['menu']['weight'] = '-40';
  $handler->display->display_options['menu']['name'] = 'main-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['people'] = $view;

  return $export;
}
