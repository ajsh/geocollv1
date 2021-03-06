#!/bin/bash

# Assumptions:
# ===========
# - Drush 5.9 or greater
# - Git 1.8.5.2 or greater
# - Execution from a shell in the webroot directory.
#
# git clone git@github.com:isubit/luggage_isu.git
# cd luggage_isu
# ./scripts/build_luggage_isu.sh
#


install_luggage_isu_bit_features() {
  # Install luggage_isu features
  drush en -y luggage_piwik luggage_isubit_vars luggage_isubit_solr features_lock_report
}
