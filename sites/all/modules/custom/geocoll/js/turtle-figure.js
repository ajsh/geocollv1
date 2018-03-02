(function ($) {

  var turtlebase = Drupal.TurtleBase = Drupal.TurtleBase || {};

  turtlebase.turtleFigure = {
    left: {
      '1': false,
      '2': false,
      '3': false,
      '4': false,
      '5': false,
      '6': false,
      '7': false,
      '8': false,
      '9': false,
      '10': false,
      '11': false,
      '12': false,
      '13': false
    },
    right: {
      '1': false,
      '2': false,
      '3': false,
      '4': false,
      '5': false,
      '6': false,
      '7': false,
      '8': false,
      '9': false,
      '10': false,
      '11': false,
      '12': false,
      '13': false
    },
    init: function(settings) {

      if (settings.turtlebase && settings.turtlebase.scutes) {

        if (settings.turtlebase.scutes.left) {
          $.each(settings.turtlebase.scutes.left, function(index, value) {
            if (value) {
              turtlebase.turtleFigure.toggle('left-scute-' + index);
            }
          });
        }

        if (settings.turtlebase.scutes.right) {
          $.each(settings.turtlebase.scutes.right, function(index, value) {
            if (value) {
              turtlebase.turtleFigure.toggle('right-scute-' + index);
            }
          });
        }

        turtlebase.turtleFigure.updateFigure();
        $('#turtle-svg').css('display', 'block');

      }

    },
    computeID: function(sex) {
      if (sex === 'All') {
        sex = '5';
      }
      function __leftpadReduce(str, val) { var padded = val; while (padded.length < 2) padded = '0' + padded; return str + padded; }
      function __rightpad(str, len, chr) { var padded = str; while (padded.length < len) padded = padded + chr; return padded; }
      var left = turtlebase.turtleFigure.getChecked('left').reduce(__leftpadReduce, "");
      var right = turtlebase.turtleFigure.getChecked('right').reduce(__leftpadReduce, "");
      return sex + __rightpad(left, 8, '0') + __rightpad(right, 6, '0');
    },
    getChecked: function(side) {
      return Object.keys(turtlebase.turtleFigure[side]).filter(function(scute) { return turtlebase.turtleFigure[side][scute] === true; });
    },
    toggle: function(scute) {
      var scute = scute;
      if (typeof scute === 'string') {
        scute = $('#turtle-svg #scutes #' + scute).get(0);
      }
      var scuteID = $(scute).attr('id');
      var scuteSide = (scuteID.startsWith('left') ? 'left' : 'right');
      var scuteNumber = scuteID.split('-')[2];
      turtlebase.turtleFigure[scuteSide][scuteNumber] = !turtlebase.turtleFigure[scuteSide][scuteNumber];
      scute.classList.toggle('active');
    },
    matchComputedID: function(computedID) {
      turtlebase.turtleFigure.reset();
      var scutes = computedID.substr(1).match(/\d{2}/g).map(function(scute) { return parseInt(scute, 10); });
      $.each(scutes, function(index, value) {
        if (value !== 0) {
          if (index < 4) {
            turtlebase.turtleFigure.toggle('left-scute-' + value);
          } else {
            turtlebase.turtleFigure.toggle('right-scute-' + value);
          }
        }
      });
    },
    reset: function() {
      $.each(turtlebase.turtleFigure.left, function(index, value) {
        if (value) {
          turtlebase.turtleFigure.toggle('left-scute-' + index);
        }
      });
      $.each(turtlebase.turtleFigure.right, function(index, value) {
        if (value) {
          turtlebase.turtleFigure.toggle('right-scute-' + index);
        }
      });
    },
    updateFigure: function() {
      $('#scutes-value-left').text(turtlebase.turtleFigure.getChecked('left').join(', '));
      $('#scutes-value-right').text(turtlebase.turtleFigure.getChecked('right').join(', '));
    }
  };

  Drupal.behaviors.TurtleFigure = {
    attach: function(context, settings) {
      $('html', context).once('TurtleFigure', function() {
        turtlebase.turtleFigure.init(settings);
      });
    }
  };

})(jQuery);