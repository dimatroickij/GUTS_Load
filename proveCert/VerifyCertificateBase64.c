VerifyCertificateBase64()
{
	web_cache_cleanup();
	web_cleanup_auto_headers();
	web_cleanup_cookies();

	//lr_output_message("Use certificate: {VerifyCertificateBase64_serts}");

	lr_start_transaction("VerifyCertificateBase64");
	
	web_reg_save_param("response","LB=","RB=","Search=Body",LAST);

	web_custom_request("request",
        "URL=http://10.215.0.95:5000/scc/crypto/api/v1/crypto/buildTrustChainForCertificate/-1",
        "Method=POST",
        "RecContentType=*/*",
        "EncType=*/*",
        "Body={VerifyCertificateBase64_serts}",
        LAST);
	
	lr_eval_json("Buffer={response}",
                 "JsonObject=json_response", LAST);
	
	lr_json_get_values("JsonObject=json_response",
                       "ValueParam=CD",
                       "QueryString=$.chain.chain[0].status",
                       LAST);
	
	if(strstr( lr_eval_string("{CD}"), lr_eval_string("{VerifyCertificateBase64_response}"))==NULL)
	{
        lr_end_transaction("VerifyCertificateBase64", LR_FAIL);
		lr_error_message( lr_eval_string("error: expected contains {VerifyCertificateBase64_response}, but got {CD}"));
		return -1;
	}
	
    lr_end_transaction("VerifyCertificateBase64", LR_PASS);
	return 0;
}
