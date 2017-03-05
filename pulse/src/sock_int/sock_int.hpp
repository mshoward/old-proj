#pragma once

/**

###Implentation of socket.h

---

Implements socket.h to accept a single connection.

Ideal use is:

- init()
- start()
- startAndDetatchAcceptAndReadThread()
- read from the output queue object until time to quit
- then call stopReadThread() - stopReadThread blocks until the reading thread has stopped.


*/


class sock_int
{
public:
	struct buf
	{
		char buffer[512];
		buf()
		{
			memset(&buffer, 0, sizeof(buffer));
		}
	};//I forget why I made this.
	
	
	
public:
	static buf emptyBuf; //I don't remember why I put this here, but I'm afraid to delete because it's late
	
	int 			stopReadThreadSig;
	void			printmsg(std::string);
	std::string		cstrTostr(char* str, int strln);
	unsigned int curr;
	unsigned int off;
	

public:
	int threadStopped;
	int sockfd; //socket file descriptor
	int newsockfd; //new socket file descriptor
	std::string name;
	std::string output; //FIFO queue for outputting reads to the rest of the program
	std::queue<std::string> storage;
	int portno; //port number
	int clilen; //address size of the client
	int n; //return value for read() / write() calls
	int errorNo;
	
	
	char buffer[256];
	
	struct sockaddr_in serv_addr;
	struct sockaddr_in cli_addr;
	std::string errorMsg;
	
	sock_int();
	~sock_int();
	
	int init(std::string str);//call this first
	void setName(std::string str);
	int start(int thisPort);//call second
	int acceptConnection();
	int startAndDetatchAcceptAndReadThread();
	int stopReadThread();
	
	
	int readOnceFromConnection();
	int acceptAndReadThread();
	
	std::string outputData();
	std::string NextLine();
	
	/** state queries */
	bool isReading();
	bool hasUnreadData();
	
};















































































