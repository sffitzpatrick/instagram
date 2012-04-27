<?php

/**
 * Returns an initialized instance of InstaPHP's
 * Instagram API object.
 * 
 */
function instagram_initialize(){
	//Check to see if the library is installed
	$library_path = libraries_get_path('Instagram-PHP-API');
	if($library_path){
		include_once $library_path;
		$api_key = variable_get('instagram_id', '');
		$api_secret = variable_get('instagram_secret', ''); 
		if (empty($api_key) || empty($api_secret)){
    	drupal_set_message(t("Instagram API keys are not set."), 'error');
    	print("Api keys not initialized");
    	return FALSE;
  	}else{
			//Initialize an instance of the $instagram object with the configuration
			$instagram = new Instagram($api_key);
				/*array(
		      'apiKey'      => $api_key,
		      'apiSecret'   => $api_secret, 
		      'apiCallback' => variable_get('instagram_callback', ''),
	    	)
			);*/
  	}
	}else{
		drupal_set_message(t('Instagram-PHP-API not loaded'), 'error');
	}
	return $instagram;
}

function instagram_get_instance(){
	static $instagram;
	
	if(empty($instagram)){
		$instagram = instagram_initialize();
	}
	
	return $instagram;	
}


function instagram_search_location($instagram, $lon = null, $lat = null){
	$instagram = instagram_get_instance();

	return $results;
}

