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
    LogicalFile.getline(name, sz, '|');
    LogicalFile.getline(phone_num, sz, '|');
    LogicalFile.read((char*)&salary, sizeof(salary));
    LogicalFile.getline(shift, sz, '|');
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
