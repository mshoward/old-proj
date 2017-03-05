#pragma once

class scheduler
{
public:
	dataBucket dirty_cache;
	std::queue<QUESTION_RET> return_queue;
	scheduler(){}
	~scheduler(){}
	
	/**
		en_cache functions
	*/
	
	/**
		FUNCTION A:
		function that reads guids from a member and member function passed to it
			calls process_request inside it --> which returns the
			question by reference --> adds to return_queue
	*/
	
	/**
		FUNCTION B:
			starts A on a separate thread
	*/
	
	/**
		
	*/
};
