<?php
/**
 * @file
 * luggage_ckeditor.features.ckeditor_profile.inc
 */

/**
 * Implements hook_ckeditor_profile_defaults().
 */
function luggage_ckeditor_ckeditor_profile_defaults() {
  $data = array(
    'CKEditor Global Profile' => array(
      'name' => 'CKEditor Global Profile',
      'settings' => array(
        'skin' => 'moono',
        'ckeditor_path' => '%l/ckeditor',
        'ckeditor_local_path' => '',
        'ckeditor_plugins_path' => '%b/sites/all/modules/luggage/luggage_ckeditor/plugins',
        'ckeditor_plugins_local_path' => '',
        'ckfinder_path' => '%m/ckfinder',
        'ckfinder_local_path' => '',
        'ckeditor_aggregate' => 'f',
        'toolbar_wizard' => 't',
        'loadPlugins' => array(),
      ),
      'input_formats' => array(),
    ),
    'WYSIWYG' => array(
      'name' => 'WYSIWYG',
      'settings' => array(
        'ss' => 2,
        'toolbar' => '[
    [\'PasteText\',\'PasteFromWord\'],
    [\'Table\',\'HorizontalRule\'],
    [\'SpecialChar\',\'Subscript\',\'Superscript\'],
    [\'Bold\',\'Italic\',\'Underline\'],
    [\'Blockquote\',\'BulletedList\',\'NumberedList\'],
    [\'JustifyLeft\',\'JustifyCenter\',\'JustifyRight\'],
    [\'Unlink\',\'Link\'],
    [\'Format\',\'RemoveFormat\'],
    [\'Image\'],
    [\'Outdent\',\'Indent\']
]',
        'expand' => 't',
        'default' => 't',
        'show_toggle' => 'f',
        'uicolor' => 'default',
        'uicolor_user' => '#025C0E',
        'use_divarea' => 'f',
        'width' => '100%',
        'lang' => 'en',
        'auto_lang' => 't',
        'language_direction' => 'default',
        'allowed_content' => 't',
        'extraAllowedContent' => '',
        'enter_mode' => 'p',
        'shift_enter_mode' => 'br',
        'font_format' => 'p;h2;h3',
        'custom_formatting' => 'f',
        'formatting' => array(
          'custom_formatting_options' => array(
            'indent' => 'indent',
            'breakBeforeOpen' => 'breakBeforeOpen',
            'breakAfterOpen' => 'breakAfterOpen',
            'breakAfterClose' => 'breakAfterClose',
            'breakBeforeClose' => 0,
            'pre_indent' => 0,
          ),
        ),
        'css_mode' => 'theme',
        'css_path' => '',
        'css_style' => 'theme',
        'styles_path' => '',
        'filebrowser' => 'none',
        'filebrowser_image' => '',
        'filebrowser_flash' => '',
        'UserFilesPath' => '%b%f/',
        'UserFilesAbsolutePath' => '%d%b%f/',
        'forcePasteAsPlainText' => 'f',
        'html_entities' => 'f',
        'scayt_autoStartup' => 't',
        'theme_config_js' => 'f',
        'js_conf' => 'CKEDITOR.config.specialChars = CKEDITOR.config.specialChars.concat( [[ \'&alpha;\', \'Greek small letter alpha\' ], [ \'&beta;\', \'Greek small letter beta\' ]] );',
        'loadPlugins' => array(
          'confighelper' => array(
            'name' => 'confighelper',
            'desc' => 'Configuration helper plugin for CKEditor',
            'path' => '%plugin_dir_extra%confighelper/',
            'buttons' => FALSE,
            'default' => 'f',
          ),
          'drupalbreaks' => array(
            'name' => 'drupalbreaks',
            'desc' => 'Plugin for inserting Drupal teaser and page breaks.',
            'path' => '%plugin_dir%drupalbreaks/',
            'buttons' => array(
              'DrupalBreak' => array(
                'label' => 'DrupalBreak',
                'icon' => 'images/drupalbreak.png',
              ),
            ),
            'default' => 't',
          ),
          'indent' => array(
            'name' => 'indent',
            'desc' => 'Plugin file: indent',
            'path' => '%plugin_dir_extra%indent/',
            'buttons' => FALSE,
            'default' => 'f',
          ),
          'indentblock' => array(
            'name' => 'indentblock',
            'desc' => 'Plugin file: indentblock',
            'path' => '%plugin_dir_extra%indentblock/',
            'buttons' => FALSE,
            'default' => 'f',
          ),
          'indentlist' => array(
            'name' => 'indentlist',
            'desc' => 'Plugin file: indentlist',
            'path' => '%plugin_dir_extra%indentlist/',
            'buttons' => FALSE,
            'default' => 'f',
          ),
          'justify' => array(
            'name' => 'justify',
            'desc' => 'Plugin file: justify',
            'path' => '%plugin_dir_extra%justify/',
            'buttons' => FALSE,
            'default' => 'f',
            'active' => 0,
          ),
          'luggage' => array(
            'name' => 'luggage',
            'desc' => 'Plugin file: luggage',
            'path' => '%plugin_dir_extra%luggage/',
            'buttons' => FALSE,
            'default' => 'f',
            'active' => 0,
          ),
        ),
      ),
      'input_formats' => array(
        'wysiwyg' => 'WYSIWYG',
      ),
    ),
  );
  return $data;
}
