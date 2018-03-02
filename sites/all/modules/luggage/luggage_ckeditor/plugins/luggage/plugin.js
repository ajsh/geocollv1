(function($) {
  CKEDITOR.plugins.add( 'luggage', {
    init: function( editor )
    {
      editor.config.hideDialogFields="image:info:txtUrl";
    }
  });

  // adapted from
  // http://skvare.com/blog/remove-tabs-and-elements-from-ckeditor-dialog-window
  CKEDITOR.on( 'dialogDefinition', function( ev )
  {
    // Take the dialog name and its definition from the event data.
    var dialogName = ev.data.name;
    var dialogDefinition = ev.data.definition;

    // Check if the definition is from the dialog we're
    // interested in (the 'image' dialog).
    if ( dialogName == 'image' )
    {
        // Remove the 'Advanced' tabs from the 'iamge' dialog.
        dialogDefinition.removeContents( 'advanced' );

        // Get a reference to the 'image Info' tab.
        //  this part does not work!!!
        //  If I can get it working we can remove the confighelper plugin
        //var infoTab = dialogDefinition.getContents( 'info' );

        // Remove unnecessary widgets from the 'image Info' tab.
        //infoTab.remove( 'txturl');
    }
  });
})(jQuery);
