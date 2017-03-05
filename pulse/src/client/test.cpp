
//g++ test.cpp -std=c++11 -pthread -Wall -o testing

#include <iostream>
//#include <chrono>
//#include <thread>
#include <string>
#include <random>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <chrono>
#include <ctime>
using std::string;
using std::cout;
using std::endl;
using namespace std;
void a(string msg, int n)
{
	cout << "Thread " << n << " says: " << msg << endl;
}


int main() 
{
	int ar[10];
	memset(ar, 0, sizeof(ar));
	for(int i = 0; i < 10; i++)
		cout << ar[i] << endl;
	minstd_rand rander;
	rander.seed(time(NULL));
	cout << "hello world" << endl;
	size_t a, b;
	a = sizeof(int) * 4;
	b = sizeof(char);
	while(a != b)
		b += sizeof(char);
	cout << b << endl;
	cout << "int: " << sizeof(int) << endl;
	cout << "short: " << sizeof(short) << endl;
	cout << "char: " << sizeof(char) << endl;
	int randed;
	randed = rander();
	for(unsigned int i = 0; i < (unsigned int)randed; i++)
		randed = rander();
	printf("int: %#0x\n", randed);
	printf("short: %#0x\n", (((unsigned short)randed) << 8) >> 8);
	printf("char: %#0x\n", (((unsigned char)randed) << 0) >> 4);
	
	return 0;
}
