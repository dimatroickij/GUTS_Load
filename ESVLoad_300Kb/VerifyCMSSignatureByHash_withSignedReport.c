VerifyCMSSignatureByHash_withSignedReport()
{
	web_cache_cleanup();
	web_cleanup_auto_headers();
	web_cleanup_cookies();

	lr_output_message(	lr_eval_string("{dataPath}/{VerifyCMSSignatureByHash_withSignedReport_file}"));
	lr_read_file(lr_eval_string("{dataPath}/{VerifyCMSSignatureByHash_withSignedReport_file}"), "request", 0);

	lr_output_message("Use file: {VerifyCMSSignatureByHash_withSignedReport_file}");

<<<<<<< HEAD
	lr_continue_on_error(1);
	
=======
>>>>>>> 52c378a8d9926d3bf02036ec7754c17fc5632fa3
	lr_start_transaction("VerifyCMSSignatureByHash_withSignedReport");
	soap_request("StepName=VerifyCMSSignatureByHash_withSignedReport",
		"URL={URL}",
		"SOAPEnvelope="
			"{request}",
		"ExpectedResponse=AnySoap",
		"ResponseParam=result",
		LAST);

	//lr_output_message("log/result: %s", lr_eval_string("{result}"));
	if(strstr( lr_eval_string("{result}"), lr_eval_string("{VerifyCMSSignatureByHash_withSignedReport_response}"))==NULL)
	{
        lr_end_transaction("VerifyCMSSignatureByHash_withSignedReport", LR_FAIL);
		lr_output_message( lr_eval_string("error: expected contains {VerifyCMSSignatureByHash_withSignedReport_response}, but got {result}"));
<<<<<<< HEAD
	}
	else
	{
		lr_end_transaction("VerifyCMSSignatureByHash_withSignedReport", LR_PASS);
	}
    lr_continue_on_error(0);
=======
		return -1;
	}

    lr_end_transaction("VerifyCMSSignatureByHash_withSignedReport", LR_PASS);
>>>>>>> 52c378a8d9926d3bf02036ec7754c17fc5632fa3
	return 0;
}
