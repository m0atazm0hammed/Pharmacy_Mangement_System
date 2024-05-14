#include "Person.h"
using namespace std;

class Employee : public Person {
private:
    int salary;
    char shift[20], phone_num[12];
public:
    Employee() {

    }
};