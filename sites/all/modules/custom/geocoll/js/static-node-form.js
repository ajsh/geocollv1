/*
 Add an active state and toggles a checkbox for clicked scutes
 */

(function ($) {

  var turtlebase = Drupal.TurtleBase = Drupal.TurtleBase || {};

  turtlebase.turtleStaticNodeForm = function() {

    $('#edit-scutes input').each(function () {
      if ($(this).attr('checked')) {
        var scuteID = $(this).attr('id').slice(18, -4);
        turtlebase.turtleFigure.toggle(scuteID);
      }
    });

    $('#turtle-svg').css('display', 'block');

    $('#edit-scutes .field-type-list-boolean').addClass('element-invisible');

    $('#turtle-svg:not(.noclick) #scutes > g').click(function(e) {
      turtlebase.turtleFigure.toggle(this);
      var $checkbox = $('#edit-field-static-' + $(this).attr('id') + '-und');
      $checkbox.attr('checked', !$checkbox.attr('checked'));
      e.preventDefault();
    });

  };

  Drupal.behaviors.StaticNodeForm = {
    attach: function(context, settings) {
      $('html', context).once('TurtleStaticNodeForm', turtlebase.turtleStaticNodeForm);
    }
  };

})(jQuery);