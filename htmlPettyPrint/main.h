#pragma once
#include <vector>
#include <iostream>
#include <fstream>
#include <string>

using std::vector;
using std::fstream;
using std::string;

class printer
{
protected:
	vector<string> datas;
	vector<string> transformed;
	string temp;
	int current;
public:
	printer(void){
		current = 0;
		temp = "";
		datas.clear();
	}
	~printer(void){
		temp.clear();
		datas.clear();
	}
	void read(fstream &file)
	{
		datas.clear();
		while(!file.eof())
		{
			std::getline(file, temp);
			datas.push_back(temp);
		}
	}
	void transform()
	{
		temp.clear();
		for(int i = 0; i < datas.size(); i++)
		{
			

		}
	}



	string getline()
	{
		temp = transformed[current];
		current++;
		return temp;
	}

};

