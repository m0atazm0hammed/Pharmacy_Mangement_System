#pragma once
#include <cstring>
#include <fstream>
#include <vector>
#include <AvailList.h>
#include <index.h>
using namespace std;

#ifdef __linux__
	#define strcpy_s strcpy
#endif

class Entity
{
    protected:
        int id;
        char name[20];
		string primary_file_name = "Entity01.txt", secondary_file_name = "Entity02.txt",
				file_name = "Entity00.txt", deleted_file_name = "EntityAvail.txt";
	public:
		Entity();
		Entity(int id, char name[20]);
		~Entity();
		Entity(Entity &other);

		index<int> primary_index;
		index<string> secondary_index;
		vector<AvailList> Avail_List;
		fstream LogicalFile;
		
		void Add();
		int Update(int);
		int Delete(int);

		int ReturnPosition(int);
		set<int>& ReturnPosition(char [20]);
		
		int FirstFit(int);
		void load_files();
		void save_files();

		void Write();
		int Size();
		void Read();

        void Name(char name[20]);
        void Id(int id);
};