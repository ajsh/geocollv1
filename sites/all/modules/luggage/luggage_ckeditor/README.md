luggage_ckeditor
===============

Maintainers
===============
ISUBIT

https://github.com/isubit/luggage_ckeditor

Features
================
A conservative implementation of the ckeditor in Drupal 7.

Text formats:
WYSIWYG - admin/config/content/formats/wysiwyg
- Allowed by authenticated.

Filtered HTML - admin/config/content/formats/filtered_html
- No roles may use this format.
- This text format is installed with the standard Drupal profile and is highly abused. We have reset it so it is unused.

Full HTML - admin/config/content/formats/full_html
- No roles may use this format
- This text format is installed with the standard Drupal profile and is dangerous and highly abused. We have reset it so it is unused.

CKEditor config changes:
- We have altered the configuration to remove the "url" field from the image properties dialog so that users cannot include images from other domains.
- The only way to include an image is to use the [insert module](https://www.drupal.org/project/insert).
- We have also removed the image properties advanced dialogue tab as we do not want users to change classes, IDs or other potentially dangerous configuration.
- Those with the authenticated user role may not escape from the CKEditor and edit source.

Principles:
================

Security
- Users need to be locked into uploading images through a Drupal field and unable to create img tags that point outside the host domain.
- Available tags and tag attributes are highly restricted to prevent CSS tampering, iframe usage, and so on. 

Simple
- Simpler is easier to use.

Included
================
Stock [ckeditor drupal module](https://www.drupal.org/project/ckeditor).

luggage_ckeditor Drupal feature.


Installation
===============

Open a command line where DRUPAL_ROOT is the root of your Drupal site:

cd DRUPAL_ROOT/sites/all/modules

git clone https://github.com/isubit/luggage_ckeditor.git

cd DRUPAL_ROOT/sites/all/libraries

git clone https://github.com/ckeditor/ckeditor-releases.git ckeditor

drush en luggage_ckeditor
			

Dependencies
----------------

- better\_formats
- ckeditor - included
- features
- image - core
- image\_resize\_filter
- insert
- wysiwyg\_filter
- ckeditor 4.x JS library
