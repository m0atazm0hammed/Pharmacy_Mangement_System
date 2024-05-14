#pragma once
#include <Person.h>
class Customer : public Person
{
	string primary_file_name = "customer01.txt", secondary_file_name = "customer02.txt",
				file_name = "customer00.txt", deleted_file_name = "customerAvail.txt";
	public:
		index<int> primary_index;
		index<string> secondary_index;
		string primary_file_name = "customer01.txt", secondary_file_name = "customer02.txt",
				file_name = "customer00.txt", deleted_file_name = "customerAvail.txt";
		Customer();
		Customer(int id, char name[20], char phone_num[20]);
		~Customer();
	
};
