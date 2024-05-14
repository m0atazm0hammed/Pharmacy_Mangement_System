#include "Customer.h"
#include "AvailList.h"
#include <vector>


Customer::Customer() : Person()
{
}

Customer::Customer(int id, char name[20], char phone_num[20]) : Person(id, name, phone_num)
{
    strcpy_s(this->name, name);
    strcpy_s(this->phone_num, phone_num);
}

Customer::Customer(Customer &other) : Person(other) { }

Customer::~Customer()
{
    save_files();
}