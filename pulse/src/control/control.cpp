#pragma once
/*
class control
{
public:
	int errorNo;
	
private:
	int config_state;
	int sock_state;
	
	int init_sock();
	int init_config();
	
public:
	int out_port;
	int mysql_port;
	sock_int dirty_sock;
	sock_int mysql_server_port; //unsure about this
	
	config configuration;
	
	control();
	~control();
	
	int init();
	
	std::string Next_dirty_sock_line();
	
};//replace control.hpp with this declaration
*/

/***************************************************************
 * private static members
 ***************************************************************/







/***************************************************************
 * public static members
 ***************************************************************/







/***************************************************************
 * private  members
***************************************************************/


int control::init_sock()
{
	int ret = 0;
	if(config_state)
	{
		dirty_sock.init("dirty sock");
		dirty_sock.start(out_port);
		dirty_sock.startAndDetatchAcceptAndReadThread();
		ret = dirty_sock.errorNo;
	}
	else
	ret = 4;
	return ret;
}

int control::init_config()
{
	int ret = configuration.init();
	if(!ret)
	{
		configuration.print_All();
		std::string dirty_sock_port = configuration.get("out_server_port");
		//std::cout << "dirty_sock port: " << dirty_sock_port << std::endl;
		out_port = std::stoi(configuration.get("out_server_port"));
		mysql_port = std::stoi(configuration.get("mysql_server_port"));
		config_state++;
	}
	return ret;
}

/***************************************************************
 * public members
 ***************************************************************/

int control::init()
{
	int ret = 0;
	config_state = 0;
	sock_state = 0;
	out_port = 0;
	mysql_port = 0;
	ret = ret | init_config();
	ret = ret | init_sock();
	return ret;
}

bool control::dirty_sock_connected()
{
	return dirty_sock.threadStopped == 0;
}

std::string control::Next_dirty_sock_line()
{
	return dirty_sock.NextLine();
}



////////////////////////////////////////////////////
/// State Queries ///
////////////////////////////////////////////////////









