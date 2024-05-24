#include "Person.h"

class Employee : public Person
{
    public:
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
        int Delete(int);
        void Add();
        int Update(int, char[20], int, char[20]);

        void Salary(int salary);
        void Shift(char shift[20]);
            
        void load_files();
        void save_files();


        int ReturnPosition(int);
        set<int> &ReturnPosition(char[20]);

        int BestFit(int);
};  