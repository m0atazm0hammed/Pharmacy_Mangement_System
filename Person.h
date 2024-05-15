#pragma once
#include "Entity.h"


class Person : public Entity
{
	protected:
		int id;
		char name[20], phone_num[20];
		string primary_file_name = "person01.txt", secondary_file_name = "person02.txt",
				file_name = "person00.txt", deleted_file_name = "personAvail.txt";
	public:
		Person();
		Person(int id, char name1[20], char phone_num1[50]);
		~Person();
		Person(Person &other);


		void Write();
		int Size();
		void Read();

		void Phone_num(char phone_num[20]);
};

