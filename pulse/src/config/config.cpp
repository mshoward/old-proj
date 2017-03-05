#pragma once
/*
class config
{
public:

private:
	std::string getWord(std::string &str);
	void stripComment(std::string &str);
	std::map<std::string, std::string> mapper;
public:
	
	int errorNo;
	std::fstream conf;
	
	config(){}
	~config(){}
	int init();
	std::string get(const char * str);
	std::string get(std::string str);
	
};
*/



/***************************************************************
 * private  members
***************************************************************/

std::string config::getWord(std::string &str)
{
	/** consumes first word of the string */
	std::string ret = "";
	int word_started = 0;
	int word_ended = 0;
	unsigned int i = 0;
	for(i = 0; (i < str.length()) && !(word_ended); i++)
	{
		//word started
		if (std::isspace(str[i]))
		{
			if(word_started)
				word_ended++;
		}
		else
		{
			word_started++;
			ret += str[i];
		}
		//during word
		
		//end word
	}
	str = str.substr(i, str.length());
	return ret;
}

void config::stripComment(std::string &str)
{
	str = ((str.find('#') == std::string::npos) ? 
		str :
		str.substr(str.length() - str.find('#'), str.length()));
}

/***************************************************************
 * public members
 ***************************************************************/



int config::init()
{
	int ret = 0;
	std::string line;
	std::string val;
	std::string test;
	std::string prop;
	
	conf.open(CONF_PATH, std::ios::in);
	if(!conf.is_open())
	{
		std::cout << "Config File Open Failed!" << std:: endl;
		errorNo = ret = -1;
		return ret;
	}
	while(!conf.eof())
	{
		line.clear();
		getline(conf, line);
		//std::cout << "Read: " << line << std::endl;
		stripComment(line);
		//std::cout << "Stripped: " << line << std::endl;
		//prop name
		prop = getWord(line);
		//std::cout << "Prop is: " << prop << std::endl;
		if(prop != "")
		{
			test = getWord(line);
			//std::cout << "test is: " << test << std::endl;
			if(test == "=")
			{
				val = getWord(line);
				//std::cout << "Val is: " << val << std::endl;
				if(val != "")
				{
					//std::cout << "mapping: " << prop << " to: " << val << std::endl;
					mapper[prop] = val;
				}
			}
		}
	}
	conf.close();
	return ret;
}

std::string config::get(const char *str)
{
	std::string newstr = "";
	int i = 0;
	while(str[i] != 0)
	{
		newstr += str[i];
		i++;
	}
	return get(newstr);
}

std::string config::get(std::string str)
{
	return mapper[str];
}


void config::print_All()
{
	std::cout << "\nConfiguration: \n" << std::endl;
	for (auto it = mapper.cbegin(); it != mapper.cend(); ++it)
	{
		std::cout << it->first << " : " << it->second << std::endl;
	}
	std::cout << std::endl;
}
////////////////////////////////////////////////////
/// State Queries ///
////////////////////////////////////////////////////








