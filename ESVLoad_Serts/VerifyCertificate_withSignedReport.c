VerifyCertificate_withSignedReport()
{
	web_cache_cleanup();
	web_cleanup_auto_headers();
	web_cleanup_cookies();

	lr_output_message(	lr_eval_string("{dataPath}/{VerifyCertificate_withSignedReport_file}"));
	lr_read_file(lr_eval_string("{dataPath}/{VerifyCertificate_withSignedReport_file}"), "request", 0);

	lr_output_message("Use file: {VerifyCertificate_withSignedReport_file}");

	lr_start_transaction("VerifyCertificate_withSignedReport");
	soap_request("StepName=VerifyCertificate_withSignedReport",
		"URL={URL}",
		"SOAPEnvelope="
			"{request}",
		"ExpectedResponse=AnySoap",
		"ResponseParam=result",
		LAST);

	//lr_output_message("log/result: %s", lr_eval_string("{result}"));
	if(strstr( lr_eval_string("{result}"), lr_eval_string("{VerifyCertificate_withSignedReport_response}"))==NULL)
	{
        lr_end_transaction("VerifyCertificate_withSignedReport", LR_FAIL);
		lr_error_message( lr_eval_string("error: expected contains {VerifyCertificate_withSignedReport_response}, but got {result}"));
		return -1;
		//return 0;
	}

    lr_end_transaction("VerifyCertificate_withSignedReport", LR_PASS);
	return 0;
}