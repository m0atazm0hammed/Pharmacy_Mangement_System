#include "Person.h"

Person::Person() {
	id = -1;
	name[0] = phone_num[0] = '\0';
}

Person::Person(int id, char name1[20], char mail1[50]):id(id) {
	strcpy_s(name, name1);
	strcpy_s(phone_num, mail1);
}

Person::Person(const Person& other) {
	id = other.id;
	strcpy_s(name, other.name);
	strcpy_s(phone_num, other.phone_num);
}