/*
 Add an active state and toggles a checkbox for clicked scutes
 */

(function ($) {

  var turtlebase = Drupal.TurtleBase = Drupal.TurtleBase || {};

  turtlebase.tabletopScrollbar = function() {

    $('.views-tabletop-scrollbar table').each(function(i) {

      $(this).wrap('<div id="views-tabletop-scrollbar-table-wrapper-' + i + '" class="table-wrapper"></div>');
      var tableWrapper = $('#views-tabletop-scrollbar-table-wrapper-' + i);

      tableWrapper.before('<div id="views-tabletop-scrollbar-scrollbar-wrapper-' + i + '" class="scrollbar-wrapper"><div class="scrollbar"></div></div>');
      var scrollbarWrapper = $('#views-tabletop-scrollbar-scrollbar-wrapper-' + i);

      $('.scrollbar', scrollbarWrapper).width($(this).width());
      scrollbarWrapper.scroll(function() {
        tableWrapper.scrollLeft(scrollbarWrapper.scrollLeft());
      });
      tableWrapper.scroll(function() {
        scrollbarWrapper.scrollLeft(tableWrapper.scrollLeft());
      });
    });

  };

  Drupal.behaviors.TabletopScrollbar = {
    attach: function(context, settings) {
      $('html', context).once('TurtlebaseTabletopScrollbar', turtlebase.tabletopScrollbar);
    }
  };

})(jQuery);