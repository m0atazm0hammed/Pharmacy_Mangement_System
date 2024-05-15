#include "Person.h"

class Employee : public Person
{
    private:
        int salary; 
        char shift[20]; //12:00AM-06:30AM

    public:
        Employee();
        Employee(int, char[20], char[20], int, char[20]);
        ~Employee();
        Employee(Employee &other);
        void Write();
		int Size();
		void Read();

        void Salary(int salary);
        void Shift(char shift[20]);

};