#include "Person.h"
#include <fstream>
#include "Entity.h"
#include "index.h"
using namespace std;


Person::Person() 
{
	id = -1;
	name[0] = phone_num[0] = '\0';
}

Person::Person(int id, char name1[20], char phone_num1[50]):id(id)
{
	strcpy_s(name, name1);
	strcpy_s(phone_num, phone_num1);
}

Person::Person(Person &other)
{
    id = other.id;
    strcpy_s(name, other.name);
    strcpy_s(phone_num, other.phone_num);  
}

Person::~Person()
{
    save_files();
}

void Person::Write()
{
    LogicalFile.put('$');
    LogicalFile.write((char*)&id, sizeof(id));
    LogicalFile.write(name, strlen(name));
    LogicalFile.put('|');
    LogicalFile.write(phone_num, strlen(phone_num));
    LogicalFile.put('|');
}

void Person::Read()
{
    streamsize sz = 0;
    LogicalFile.get();
    LogicalFile.read((char*)&id, sizeof(id));
    LogicalFile.getline(name, sz, '|');
    LogicalFile.getline(phone_num, sz, '|');
}

int Person::Size()
{
    return 7 + strlen(name) + strlen(phone_num);
}

void Person::Phone_num(char phone_num[20])
{
    strcpy_s(this->phone_num, phone_num);
}