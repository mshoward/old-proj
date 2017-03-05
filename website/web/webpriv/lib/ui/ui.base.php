
<?php
	//requires
	require_once("/webpriv/lib/util/util.base.php");
	require_once("/webpriv/lib/ui/ui.globals.php");
?>


<?php
	
	function log_ui_error()
	{
		log_error($GLOBALS['ui_error']);
	}
	
	function start_tag($tagname)
	{
		if (! $GLOBALS['started_tag'])
		{
			$GLOBALS['started_tag'] = true;
			echo "<{$tagname}";
			return false;
		}
		else
		{
			$GLOBALS['ui_error'] = "start_tag failed because a tag was already started";
			log_ui_error();
			return true;
		}
	}
	
	function close_start_tag()
	{
		if ($GLOBALS['started_tag'])
		{
			echo ">";
			$GLOBALS['started_tag'] = false;
			return false;
		}
		else
		{
			$GLOBALS['ui_error'] = "close_start_tag failed because no tag started";
			log_ui_error();
			return true;
		}
		
	}
	
	function add_tag_attribute($attribute, $value)
	{
		if ($GLOBALS['started_tag'])
		{
			echo "{$attribute}=\"{$value}\"";
			return false;
		}
		else
		{
			$GLOBALS['ui_error'] = "add_tag_attribute failed because no tag started";
			log_ui_error();
			return true;
		}
	}
	
	function close_start_tag_no_body()
	{
		if ($GLOBALS['started_tag'])
			echo "/>";
		$GLOBALS['started_tag'] = false;
	}
	
	function end_tag($tagname)
	{
		echo "</{$tagname}>";
	}

	function start_html_doc()
	{
		echo "<!DOCTYPE html>" . newline();
		start_tag('html');
		close_start_tag();
	}
	
	function start_body()
	{
		echo "<body>";
	}
	
	function start_head()
	{
		echo "<head>";
	}
	
	function end_head()
	{
		echo "</head>";
	}
	
	function end_body()
	{
		echo "</body>";
	}
	
	function end_html_doc()
	{
		echo "</html>";
	}
	
	
	
	
	
?>
