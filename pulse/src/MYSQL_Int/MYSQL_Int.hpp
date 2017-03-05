#pragma once

class MYSQL_Int
{
	/**
		This should produce a uniform output in order to provide uniform input for 
		the dirty_scheduler.  This is basically a mapping from the database to the
		cache.
		
		************************
		** connection process **
		************************
				|
				V
		******************************
		** f(MYSQL_DATA_STRUCTURES) **
		******************************
				|
				V
		*********************
		** dirty_scheduler **
		*********************
				|
				V
		*****************
		** dirty_cache **
		*****************
	*/
	
	std::string ip;
	
	int fillStructure(std::vector *send_to);
	MYSQL *database_handle;
	
	
};
