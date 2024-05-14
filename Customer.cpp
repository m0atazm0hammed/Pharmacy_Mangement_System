#include "Customer.h"

// Global Variable(s)
fstream LogicalFile;

index<int> Customer::primary_index;
index<string> Customer::secondary_index;
string Customer::primary_file_name = "Customer_01.txt", Customer::secondary_file_name = "Customer_02.txt", 
       Customer::file_name = "Customer_00.txt", Customer::deleted_file_name = "Customer_03.txt";


Customer::Customer() : Person()
{
}

Customer::Customer(int id, char name[20], char mail[50]) : Person(id, name, mail)
{
}

Customer::Customer(const Customer &other) : Person(other)
{
}

void Customer::AddCustomer()
{
    
    LogicalFile.open("Customer.txt", ios::in | ios::out | ios::app | ios::binary);
    int offset = LogicalFile.tellp();
    primary_index.add(id, offset);
    secondary_index.add(name, offset);
    Write(LogicalFile);
    LogicalFile.close();
}

void Customer::Write(fstream& file) {
    // *$
    file.put('$');
    file.write((char*)&id, sizeof(id));
    file.write(name, strlen(name));
    file.put('|');
    file.write(phone_num, strlen(phone_num));
    file.put('|');
}

void Customer::read(fstream& file) {
    file.get();
    file.read((char*)&id, sizeof(id));
    file.read(name, '|');
    file.read(phone_num, '|');
}

int Customer::Update(int id, char phone_num[50])
{
    int pos = ReturnPosition(id);
    if (pos == -1) {
        return 0;
    }
    fstream file(file_name, ios::binary | ios::in | ios::out);
    file.seekg(pos, ios::beg);
    read(file);
    strcpy_s(this->phone_num, phone_num);
    file.seekp(pos, ios::beg);
    Write(file);
    file.close();
    return 1;
}

int Customer::ReturnPosition(int)
{
	if (primary_index.keys.find(id) == primary_index.keys.end())
    {
		return -1;
	}
	return *primary_index.keys[id].begin();
}

set<int>& Customer::ReturnPosition(char name[20])
{
    return secondary_index.keys[string(name)];
}

int Customer::Delete(int id) {
    int pos = ReturnPosition(id);
    if (pos == -1) {
        return 0;
    }
    fstream file(file_name, ios::in | ios::out | ios::binary);
    file.seekp(pos, ios::beg);
    file.put('*');
}