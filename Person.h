#pragma once
#include<cstring>
class Person
{
protected:
	int id;
	char name[20], phone_num[50];
public:
	Person();
	Person(int id, char name1[20], char phone_num1[50]);
	Person(const Person& other);
};

