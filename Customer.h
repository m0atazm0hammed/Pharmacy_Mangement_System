#pragma once
#include "Person.h"
#include "varlen.h"
#include "index.h"
#include <fstream>
class Customer : public Person
{
public:
	static index<int> primary_index;
	static index<string> secondary_index;
	static index<int> deleted;
	static string primary_file_name, secondary_file_name, file_name, deleted_file_name;
	Customer();
	Customer(int id, char name[20], char phone_num[50]);
	Customer(const Customer &other);
	void AddCustomer();
	void Write(fstream&);
	void read(fstream&);
	int Update(int, char[50]);
	void ShowEmployeesData(ostream &);
	void ShowAnEmployee(ostream &);
	int ReturnPosition(int);
	set<int>& ReturnPosition(char [20]);
	
	int Exit();
	int Delete(int);
	void FirstFit();
};
