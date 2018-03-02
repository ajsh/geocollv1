/*
 Add an active state and toggles a checkbox for clicked scutes
 */

(function ($) {

  var turtlebase = Drupal.TurtleBase = Drupal.TurtleBase || {};

  turtlebase.turtleObservationsPage = function() {

    $('#edit-field-static-computed-id-value').change(function () {
      var computedID = $(this).val();
      if (typeof computedID === 'string' && computedID.length === 15) {
        var sex = computedID.slice(0, 1);
        if (sex === '4') {
          $('#edit-field-static-id-starts-with-four-value').val(1);
        } else {
          $('#edit-field-static-id-starts-with-four-value').val(0);
          $('#edit-field-static-sex-value').val(sex);
        }
        turtlebase.turtleFigure.matchComputedID(computedID);
      }
    });

    $('#turtle-svg').css('display', 'block');

    $('#turtle-svg:not(.noclick) #scutes > g').click(function(e) {
      turtlebase.turtleFigure.toggle(this);
      $('#edit-field-static-computed-id-value').val(turtlebase.turtleFigure.computeID($('#edit-field-static-sex-value').val()));
      e.preventDefault();
    });

  };

  Drupal.behaviors.TurtleObservationsPage = {
    attach: function(context, settings) {
      $('html', context).once('TurtleObservationsPage', turtlebase.turtleObservationsPage);
    }
  };

})(jQuery);