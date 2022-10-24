#include <iostream>
using namespace std;

class Person
{
private:
    string name;
    int age;

public:
    Person();
    ~Person();
    string getName();
    int getAge();
    void set(string n, int a);
};

Person::Person()
{
    cout << "생성" << endl;
}

Person::~Person()
{
    cout << name << " 소멸" << endl;
}

string Person::getName()
{
    return name;
}

int Person::getAge()
{
    return age;
}

void Person::set(string n, int a)
{
    name = n;
    age = a;
}