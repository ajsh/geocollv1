/*
 Add an active state and toggles a checkbox for clicked scutes
 */

(function ($) {

  var turtlebase = Drupal.TurtleBase = Drupal.TurtleBase || {};

  turtlebase.turtleDataEntryForm = function() {

    $('#edit-scutes input').each(function () {
      if ($(this).attr('checked')) {
        var scuteID = $(this).attr('id').slice(25, -4);
        turtlebase.turtleFigure.toggle(scuteID);
      }
    });

    turtlebase.turtleFigure.updateFigure();
    $('#turtle-svg').css('display', 'block');

    $('#edit-scutes .field-type-list-boolean').addClass('element-invisible');

    $('#turtle-svg:not(.noclick) #scutes > g').click(function(e) {
      turtlebase.turtleFigure.toggle(this);
      turtlebase.turtleFigure.updateFigure();
      var $checkbox = $('#edit-static-field-static-' + $(this).attr('id') + '-und');
      $checkbox.attr('checked', !$checkbox.attr('checked'));
      e.preventDefault();
    });

    $('#edit-observation-field-observation-time-unknown-und').change(function() {
      if($(this).attr('checked')) {
        $('#edit-observation-field-observation-date-und-0-value-timeEntry-popup-1').val('00:00');
      }
    });

  };

  Drupal.behaviors.TurtleDataEntryForm = {
    attach: function(context, settings) {
      $('html', context).once('TurtleDataEntryForm', turtlebase.turtleDataEntryForm);
    }
  };

})(jQuery);