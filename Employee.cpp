#include "Employee.h"

Employee::Employee() : Person(), salary(-1)
{
shift[0] = '\0';
    primary_file_name = "employee01.txt", secondary_file_name = "employee02.txt",
				file_name = "employee00.txt", deleted_file_name = "employeeAvail.txt";
    load_files();
}

Employee::Employee(int id, char name[20], char phone_num[20], int salary, char shift[20]) : Person(id, name, phone_num), salary(salary)
{
    strcpy_s(this->shift, shift);
    primary_file_name = "employee01.txt", secondary_file_name = "employee02.txt",
				file_name = "employee00.txt", deleted_file_name = "employeeAvail.txt";
    load_files();
}

Employee::Employee(Employee &other) : Person(other), salary(other.salary)
{
    load_files();
    strcpy_s(shift, other.shift);
}

Employee::~Employee()
{
    save_files();
}

void Employee::Write()
{
    
    LogicalFile.put('$');
    LogicalFile.write((char*)&id, sizeof(id));
    LogicalFile.write(name, strlen(name));
    LogicalFile.put('|');
    LogicalFile.write(phone_num, strlen(phone_num));
    LogicalFile.put('|');
    LogicalFile.write((char*)&salary, sizeof(salary));
    LogicalFile.write(shift, strlen(shift));
    LogicalFile.put('|');
}

void Employee::Read()
{
    streamsize sz = 0;
    LogicalFile.get();
    LogicalFile.read((char*)&id, sizeof(id));
    LogicalFile.getline(name, 20, '|');
    LogicalFile.getline(phone_num, 20, '|');
    LogicalFile.read((char*)&salary, sizeof(salary));
    LogicalFile.getline(shift, 20, '|');
}

int Employee::Size()
{
    return 12 + strlen(name) + strlen(phone_num) + strlen(shift);
}

void Employee::Salary(int salary)
{
    this->salary = salary;
}

void Employee::Shift(char shift[20])
{
    strcpy_s(this->shift, shift);
}


void Employee::Add()
{

    LogicalFile.open(file_name, ios::in | ios::out | ios::binary);
    int offset = BestFit(Size());

    if (offset == -1)
    {
        LogicalFile.seekp(0, ios::end);
        offset = LogicalFile.tellp();
    }
    LogicalFile.seekp(offset, ios::beg);
    Write();
    indexes.primary_keys[id].insert(offset);
    indexes.secondary_keys[string(name)].insert(id);
    LogicalFile.close();
}

int Employee::Update(int id, char phone_num[20], int salary, char shift[20])
{
    int pos = ReturnPosition(id);
    if (pos == -1)
    {
        return 0;
    }
    LogicalFile.open(file_name, ios::binary | ios::in | ios::out);
    LogicalFile.seekg(pos, ios::beg);
    Read();
    LogicalFile.seekp(pos, ios::beg);
    strcpy_s(this->phone_num, phone_num);
    this->salary = salary;
    strcpy_s(this->shift, shift);
    Write();
    LogicalFile.close();
    return 1;
}