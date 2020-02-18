VerifyWSS_withSignedReport()
{
	web_cache_cleanup();
	web_cleanup_auto_headers();
	web_cleanup_cookies();

	lr_output_message(	lr_eval_string("{dataPath}/{VerifyWSS_withSignedReport_file}"));
	lr_read_file(lr_eval_string("{dataPath}/{VerifyWSS_withSignedReport_file}"), "request", 0);

	lr_output_message("Use file: {VerifyWSS_withSignedReporte_file}");

	lr_start_transaction("VerifyWSS_withSignedReport");
	soap_request("StepName=VerifyWSS_withSignedReport",
		"URL={URL}",
		"SOAPEnvelope="
			"{request}",
		"ExpectedResponse=AnySoap",
		"ResponseParam=result",
		LAST);

	//lr_output_message("log/result: %s", lr_eval_string("{result}"));
	if(strstr( lr_eval_string("{result}"), lr_eval_string("{VerifyWSS_withSignedReport_response}"))==NULL)
	{
        lr_end_transaction("VerifyWSS_withSignedReport", LR_FAIL);
		lr_output_message( lr_eval_string("error: expected contains {VerifyWSS_withSignedReport_response}, but got {result}"));
		return -1;
	}

    lr_end_transaction("VerifyWSS_withSignedReport", LR_PASS);
	return 0;
}