#pragma once

class dataBucket
{
public:
	///heaps
	std::vector<QUESTION> question_heap;
	
	///caches
	std::vector<QUESTION> question_cache;
	std::vector<USER> recent_users;
	std::queue<RESPONSE> response_queue;
	std::vector<QUESTION_HISTORY_ENTRY> question_history_cache;
	std::vector<DEMOGRAPHIC> demographic_cache;
private:
	
public:
	dataBucket(){}
	~dataBucket(){}
	
	void build_question_heap_from_cache();
	void queue_response(RESPONSE &res);
	void cache_question(QUESTION &quest);
	void cache_question_hist(QUESTION_HISTORY_ENTRY &hist);
	void cache_demo(DEMOGRAPHIC &dem);
	void cache_user(USER &usr);
	void cache_user(GUID &guid);
	void cache_user(std::string &guid);
	
	bool in_cache(QUESTION &quest);
	bool in_cache(QUESTION_HISTORY_ENTRY &hist);
	bool in_cache(DEMOGRAPHIC &dem);
	bool in_cache(USER &usr);
	bool in_cache(GUID &guid);
	bool in_cache(std::string &guid);
	
	
	QUESTION& process_request(GUID &guid);
	void process_response(RESPONSE &res);
	
	
	
};
