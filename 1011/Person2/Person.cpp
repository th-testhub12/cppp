#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring> //C의 string.h
using namespace std;

class Person
{
private:
    char *name;
    int id;

public:
    Person(int id, const char *name) //생성자에 const 필요 왜????????????????????
    {
        this->id = id;
        int len = strlen(name) + 1; // +1 = null
        this->name = new char[len];
        strcpy(this->name, name);
    }
    Person(const Person &person)
    {
        this->id = person.id;
        int len = strlen(person.name);
        this->name = new char[len + 1];
        strcpy(this->name, person.name);
        // cout << "복사생성자" << this->name << endl;
    }
    ~Person()
    {
        if (name)
            delete[] name; //생성자에서 new 한 것을 delete
    }
    void changeName(const char *name)
    {
        if (strlen(name) > strlen(this->name))
            return;
        strcpy(this->name, name); //기존 이름 메모리 공간이 충분한 경우에만 이름 바꾸기
    }
    void show()
    {
        cout << id << " : " << name << endl;
    }
};

int main()
{
    Person father(1, "Father");
    Person daughter(father);

    father.show();
    daughter.show();
    daughter.changeName("Grace");
    father.show();
    daughter.show();
}