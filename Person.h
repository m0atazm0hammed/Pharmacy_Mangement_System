#pragma once
#include "Entity.h"


class Person : public Entity
{
	public:
		int id;
		char name[20], phone_num[20];
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

