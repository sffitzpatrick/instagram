instagram
=========

Drupal module using a simple Instagram PHP API to help developers integrate Instagram with their site. Note that this module is intended for developer use: unless required as a dependency by another module, no end-user functionality is provided.

Installation
============

1)	Install module and dependencies
2)	Add Instagram-PHP-API into sites/[yoursite]/libraries:
			https://github.com/cosenary/Instagram-PHP-API
		The path should be something like sites/all/libraries/Instagram-PHP-API/instagram.class.php
3)	Enable the module and dependencies
4)	Provide the credentials for your Instagram app in the admin ui:
			Configuration-->Instagram (admin/config/instagram)

Roadmap
=======

1)	Once Libraries API 2.x has been adopted, switch over
2)	Determine a better Instagram PHP API implementation to integrate with
3)	Provide functions to link Drupal/Instagram accounts, use the user-specific
		functions provided by the Instagram API.