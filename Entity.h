#pragma once
#include <cstring>
#include <fstream>
#include <vector>
#include "AvailList.h"
#include "index.h"
using namespace std;

#ifdef __linux__
#define strcpy_s strcpy
#endif

class Entity
{
public:
	int id;
	char name[20];
	string primary_file_name = "Entity01.txt", secondary_file_name = "Entity02.txt",
		   file_name = "Entity00.txt", deleted_file_name = "EntityAvail.txt";
	Entity();
	Entity(int id, char name[20]);
	~Entity();
	Entity(Entity &other);

	indx indexes;
	vector<AvailList> Avail_List;
	fstream LogicalFile;


	int Count(int);

	void Name(char name[20]);
	void Id(int id);
};