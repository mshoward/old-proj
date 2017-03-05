#pragma once
/***************************************************************
 * private static members
 ***************************************************************/







/***************************************************************
 * public static members
 ***************************************************************/
 
/***************************************************************
 * private  members
***************************************************************/
void sock_int::printmsg(std::string str)
{
	std::cout << str << std::endl;
}


std::string sock_int::cstrTostr(char* str, int c)
{
	/** str should be null terminated.  this will segfault if it's not. */
	std::string ret = "";
	for(int i = 0; (i < c); i++)
		ret += str[i];
	return ret;
}


/***************************************************************
 * public members
 ***************************************************************/
////////////////////////////////////////////////////
/// State Queries ///
////////////////////////////////////////////////////

bool sock_int::isReading()
{
	return threadStopped == 0;
}
bool sock_int::hasUnreadData()
{
	return !storage.empty();
}




sock_int::sock_int()
{
	sockfd = 0;
	newsockfd = 0;
	portno = 0;
	clilen = 0;
	n = 0;
	errorNo = 0;
	stopReadThreadSig = 0;
	threadStopped = 1;
	memset(&buffer, 0, sizeof(buffer));
	#ifdef PULSE_DEBUG
	//printmsg("sock_int created");
	#endif
}
sock_int::~sock_int()
{
}



//errorNo = -1 == failure to open socket
int sock_int::init(std::string str)
{
	setName(str);
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0)
	{
		errorMsg = "Error opening socket";
		errorNo = -1;
		return errorNo;
	}
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	clilen = sizeof(cli_addr);
	#ifdef PULSE_DEBUG
	printmsg(name + " initialized");;
	#endif
	//OutputStream.str(output);
	curr = 0;
	off = 0;
	return errorNo;
}

void sock_int::setName(std::string str)
{
	name = str;
}


//errorNo = -2 error on binding to port
//binds and begins listening for connections
int sock_int::start(int thisPort)
{
	#ifdef PULSE_DEBUG
	printmsg("starting " + name + "...");
	printmsg("with parameter " + std::to_string(thisPort));
	#endif
	portno = thisPort;
	serv_addr.sin_port = htons(portno);
	if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
	{
		errorMsg = "ERROR on binding";
		errorNo = -2;
		return errorNo;
	}
	listen(sockfd, 128);
	#ifdef PULSE_DEBUG
	printmsg(name + " started");
	#endif
	return errorNo;
}


//errorNo = -3 on accepting connection error
int sock_int::acceptConnection()
{
	newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, (unsigned int *) &clilen);
	if (newsockfd < 0)
	{
		errorMsg = "Error accepting connection";
		errorNo = -3;
		return errorNo;
	}
	#ifdef PULSE_DEBUG
	printmsg("sock_int connection accepted");
	#endif
	return errorNo;
}
//errorNo = -4 on reading from socket error
int sock_int::readOnceFromConnection()
{
	#ifdef PULSE_DEBUG
	//printmsg("sock_int message read begin...");
	#endif
	memset(&buffer, 0, sizeof(buffer));
	n = read(newsockfd, buffer, 255);
	if(n < 0)
	{
		errorMsg = "Error reading from socket";
		errorNo = -4;
		return errorNo;
	}
	#ifdef PULSE_DEBUG
	//printmsg("sock_int message of " + std::to_string(n) + " bytes read:");
	#endif
	std::string temp(buffer);
	std::cout << temp << std::endl;
	
	return n;
}

int sock_int::acceptAndReadThread()
{
	buf ThisBuf;
	int c = 1; 
	acceptConnection();//blocks until connection? need to test
	while(stopReadThreadSig && c > 0)
	{
		memset(ThisBuf.buffer, 0, 512);
		c = read(newsockfd, ThisBuf.buffer, 511);
		if (c < 0)
		{
			errorMsg = "Error reading from socket";
			errorNo = -4;
			return errorNo;
		}
		storage.push(cstrTostr(ThisBuf.buffer, c));
		//OutputStream.str(output);
	}
	threadStopped = 1;
	return 0;
}

int sock_int::startAndDetatchAcceptAndReadThread()
{
	stopReadThreadSig = 1;
	threadStopped = 0;
	std::thread newThread(&sock_int::acceptAndReadThread, this); //readThread() in it's own thread
	newThread.detach();
	return 0;
}


int sock_int::stopReadThread()
{
	stopReadThreadSig = 0;
	while(!threadStopped);
	return 0;
}



std::string sock_int::outputData()
{
	if(!storage.empty())
	{
		std::string ret = storage.front();
		storage.pop();
		return ret;
	}
	else
	return "";
}

std::string sock_int::NextLine()
{
	std::string ret = "";
	unsigned int i;
	char c;
	if(!storage.empty())
	{
		//std::cout << "Current buffer holds: '" << storage.front() << "'" << std::endl;
		for(i = 0; !(storage.empty()); i++)
		{
			//std::cout << "no seg" << std::endl;
			c = storage.front()[i];
			//std::cout << "no seg" << std::endl;
			if (std::isspace(c))
			{//if it's a new line, it's time to return, but not before substringing the buffer
				if (i+1 >= storage.front().length())//if there is nothing left in the buffer
				{
					storage.pop();
					//std::cout << "ended in space\nNew buffer holds: '" << storage.front() << "'" << std::endl;
				}
				else
					storage.front() = storage.front().substr(i+1, storage.front().length());
					//else reduce the buffer by amount consumed
				return ret;
			}
			else
			{
				//if not a new line, add it to the return string
				ret += c;
				//if it's the end of the front buffer, pop the front buffer off, reset i
				if (i+1 >= storage.front().length())
				{
					storage.pop();
					///debug code
					///if(!storage.empty())
					///	std::cout << "Continuing\nNew buffer holds: '" << storage.front() << "'" << std::endl;
					///end debug code
					i = -1;
				}
			}
		}
		return ret;
	}
	else
	return EMPTYSTRING;
}







