#pragma once
class control
{
public:
	int errorNo;
	
private:
	int config_state;
	int sock_state;
	
public:
	int init_sock();
	int init_config();
	
public:
	int out_port;
	int mysql_port;
	
	sock_int dirty_sock;
	scheduler dirty_scheduler;
	//sock_int mysql_server_port; //unsure about this
	
	config configuration;
	
	control(){}
	~control(){}
	
	int init();
	bool dirty_sock_connected();
	std::string Next_dirty_sock_line();
	/**
		FUNCTION A:
			takes the first item on dirty_scheduler return_queue and sends it to 
	*/
	
};//replace control.hpp with this declaration
