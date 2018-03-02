<div id="turtle-data-entry-form-enter-data" class="turtle-data-entry-form">
  <div class="form-row">
    <div class="pane grid-3">
      <?php print render($form['observation']); ?>
    </div>
    <?php if (isset($form['static'])): ?>
    <div class="pane grid-3">
      <div class="scutes-values">
        <p class="scutes-value"><strong>Left:</strong> <span id="scutes-value-left"></span></p>
        <p class="scutes-value"><strong>Right:</strong> <span id="scutes-value-right"></span></p>
      </div>
    </div>
    <?php endif; ?>
    <?php if (isset($form['nest'])): ?>
    <div class="pane grid-3">
        <?php print render($form['nest']); ?>
    </div>
    <?php endif; ?>
  </div>
  <div class="form-row">
    <?php if (isset($form['dynamic'])): ?>
    <div class="pane grid-3">
      <?php
        hide($form['dynamic']['field_dynamic_num_pectoral_ridge']);
        hide($form['dynamic']['field_dynamic_pecridge_notes']);
        hide($form['dynamic']['field_dynamic_notes']);
        print render($form['dynamic']);
      ?>
    </div>
    <?php endif; ?>
    <?php if (isset($form['static'])): ?>
    <div class="pane grid-3">
      <?php print render($form['static']['scutes']); ?>
      <?php print render($form['static']['field_static_sex']); ?>
      <?php print render($form['static']['field_static_left_scute_13']); ?>
      <?php print render($form['static']['field_static_right_scute_13']); ?>
      <?php print render($form['static']['field_static_id_starts_with_four']); ?>
      <?php print render($form['static']); ?>
    </div>
    <?php endif; ?>
    <?php if (isset($form['nobs'])): ?>
    <div class="pane grid-3">
        <?php
          hide($form['nobs']['field_nobs_nest_notes']);
          print render($form['nobs']);
        ?>
    </div>
    <?php endif; ?>
  </div>
  <?php if (isset($form['dynamic'])): ?>
  <div class="form-row">
    <div class="pane grid-full">
      <?php print render($form['dynamic']['field_dynamic_num_pectoral_ridge']); ?>
      <?php print render($form['dynamic']['field_dynamic_pecridge_notes']); ?>
      <?php print render($form['dynamic']['field_dynamic_notes']); ?>
    </div>
  </div>
  <?php endif; ?>
  <?php if (isset($form['nobs'])): ?>
  <div class="form-row">
    <div class="pane grid-full">
      <?php print render($form['nobs']['field_nobs_nest_notes']); ?>
    </div>
  </div>
  <?php endif; ?>
  <?php if (isset($form['eggs'])): ?>
  <div class="form-row">
    <div class="pane grid-full">
      <?php print render($form['eggs']); ?>
    </div>
  </div>
  <?php endif; ?>
  <?php print drupal_render_children($form); ?>
</div>
