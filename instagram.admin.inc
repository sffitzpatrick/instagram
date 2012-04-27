<?php
/**
 * Menu callback; Display the settings form for Instagram.
 */
function instagram_settings_form($form, &$form_state){

  $form['instagram_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Client ID'),
    '#size' => 50,
    '#maxlengh' => 50,
    '#description' => t('To use the Instagram API, you must <a href="http://instagr.am/developer/register">register your app with Instagram</a> and enter your Client Id here.'),
    '#default_value' => variable_get('instagram_id', ''),
  );
  $form['instagram_secret'] = array(
    '#type' => 'textfield',
    '#title' => t('Client Secret'),
    '#size' => 50,
    '#maxlengh' => 50,
    '#description' => t('To use the Instagram API, you must <a href="http://instagr.am/developer/register">register your app with Instagram</a> and enter your Client Secret here.'),
    '#default_value' => variable_get('instagram_secret', ''),
  );
  $form['instagram_callback'] = array(
    '#type' => 'textfield',
    '#title' => t('API Callback'),
    '#size' => 100,
    '#maxlengh' => 128,
    '#description' => t('To use the Instagram API, you must <a href="http://instagr.am/developer/register">register your app with Instagram</a> and enter your API Callback here.'),
    '#default_value' => variable_get('instagram_callback', ''),
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
    '#weight' => 50,
  );

  return $form;	
}

/**
 * Form validation function for instagram_settings_form().
 */
function instagram_settings_form_validate($form, &$form_state) {
  // Remove trailing spaces
  $form_state['values']['instagram_id'] = trim($form_state['values']['instagram_id']);
  $form_state['values']['instagram_secret'] = trim($form_state['values']['instagram_secret']);
  $form_state['values']['instagram_callback'] = trim($form_state['values']['instagram_callback']);


  // Do some basic data input validation.
  if (strlen($form_state['values']['instagram_id']) != 32) {
    form_error($form['instagram_id'], t('The Client ID must be a 32 character-long string.'));
  }
  if (strlen($form_state['values']['instagram_secret']) != 32) {
    form_error($form['instagram_secret'], t('The Client ID must be a 32 character-long string.'));
  }
  //@todo: insert validation for the callback
}

/**
 * Form submission function for instagram_settings_form().
 */
function instagram_settings_form_submit($form, &$form_state) {
	//Set variables
  variable_set('instagram_id', $form_state['values']['instagram_id']);
  variable_set('instagram_secret', $form_state['values']['instagram_secret']);
  variable_set('instagram_callback', $form_state['values']['instagram_callback']);


	drupal_set_message(t('The configuration options have been saved.'));
}