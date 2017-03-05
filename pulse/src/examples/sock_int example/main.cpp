#include "main.hpp"
////g++ test.cpp -std=c++11 -pthread -Wall -o testing

void pmsg(std::string str)
{
	
	std::cout << str;
	std::cout.flush();
}

int main(int argc, char *argv[])
{
	sock_int sox;
	if(!sox.init())
	{
		if(!sox.start(atoi(argv[1])))
		{
			for(int i = 0; i < 3; i++)
			{
				//sox.acceptConnection();
				sox.startAndDetatchAcceptAndReadThread();
				sox.startAndDetatchAcceptAndReadThread();
				sox.startAndDetatchAcceptAndReadThread();
				while(sox.isReading())
				{
					if(sox.hasUnreadData())
					{
						pmsg("extracted data:\n");
						pmsg(sox.outputData());
						
					}
				}
				while(sox.hasUnreadData())
				{
					pmsg("extracted data:\n");
					pmsg(sox.outputData());
				}
			}
			
		}
		else
		{
			pmsg("start fail");
			pmsg(std::to_string(sox.errorNo));
		}
	}
	else
	{
		pmsg("init fail");
	}
	pmsg(sox.output);
	return 0;
}
