#pragma once
#include <map>
#include<string>
#include<fstream>
#include <set>
using namespace std;
template<class T>
class index
{

public:
	std::map<T, set<int>> keys;
	void write(std::string&);
	void read(std::string&);
	void add(T, int);
	void update(T, int, int);
};





