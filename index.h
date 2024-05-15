#pragma once
#include <map>
#include<string>
#include <set>
using namespace std;
class indx
{

public:
	indx();
	std::map<int, set<int>> primary_keys;
	std::map<string, set<int>> secondary_keys;
	void write(std::string&, std::string&);
	void read(std::string&, std::string&);
};





