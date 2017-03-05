<?php

	$GLOBALS['util_log_file'] = "/weblogs/php_log.log";

	function newline()
	{
		return "\r\n";
	}
	
	function set_log_file($fileName)
	{
		$GLOBALS['util_log_file'] = "/weblogs/$fileName";
	}
	
	function log_error($errorMessage)
	{
		$fd = fopen($GLOBALS['util_log_file'], "a");
		if ($fd)
		{
			fwrite($fd, time()."\t".$errorMessage.newline());
		}
		else
		{
			echo "cannot find logfile or create it.\r\n<br>";
		}
	}
?>
