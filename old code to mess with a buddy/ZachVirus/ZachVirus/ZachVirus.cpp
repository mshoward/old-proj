// ZachVirus.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
//#include "Windows.h"
#include <Windows.h>



int _tmain(int argc, _TCHAR* argv[])
{
	FreeConsole();
	std::string str;
	POINT currPos;
	//std::cout << "hello world" << std::endl;
	GetCursorPos((LPPOINT)(&currPos));
	for(int i = 1; i != 0; i++)
	{
		GetCursorPos((LPPOINT)(&currPos));
		while((currPos.x != 0) || (currPos.y != 0))
		{
			GetCursorPos((LPPOINT)(&currPos));
			//std::cout << currPos.x << " " << currPos.y << std::endl;
			SetCursorPos(currPos.x - 1, currPos.y - 1);
			Sleep(5);
		}
		Sleep(120000);
	}
	//std::cin >> str;
	return 0;
}

