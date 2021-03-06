<?php
/**
 * @author rlfrahm
 * @date 10/6/14
 * @time 3:32 PM
 */
class LuggageNewsTest extends PHPUnit_Extensions_Selenium2TestCase {
  protected function setUp() {
    $this->setBrowser('firefox');
    $this->setBrowserUrl('http://local.dev/luggage');
  }

  /**
   * Tests the title
   */
  public function testPeoplePage() {
    $title = 'News';
    $this->url('/news');
    $element = $this->byId('page-title');
    $this->assertEquals($title, $element->text());
  }
}