#include <iostream>
#include <string>
using namespace std;

class Person
{
private:
    string name;
    int age;

public:
    Person() : Person("noname", 0)
    {
    }
    Person(string name, int age)
    {
        cout << (this->name = name) << "의 생성자 호출됨" << endl;
        this->age = age;
    }
    Person(const Person &p)
    {
        cout << (this->name = p.name) << "의 복사생성자 호출됨" << endl;
        this->age = p.age;
    }
    ~Person()
    {
        cout << this->name << "의 소멸자 호출됨" << endl;
    }
    string getName()
    {
        return this->name;
    }
    int getAge()
    {
        return this->age;
    }
    void set(string name, int age)
    {
        this->name = name;
        this->age = age;
    }
};

void showPersonByValue(Person p)
{
    cout << "이름 = " << p.getName() << ", 나이 = " << p.getAge() << endl;
}

void showPersonByRef(Person &p)
{
    cout << "이름 = " << p.getName() << ", 나이 = " << p.getAge() << endl;
}

int main()
{
    cout << "-------------------------------" << endl;

    // 1) 사람 수 n 입력받음
    int n;
    cout << "사람 수 : ";
    cin >> n;

    // 2) n개의 원소를 가지는 Person의 동적배열 생성
    Person *p = new Person[n];

    // 3) 각 배열원소의 이름과 나이를 입력받아 set 함수로 이름과 나이를 변경
    string name;
    int age;
    for (int i = 0; i < n; i++)
    {
        cout << "사람" << i + 1 << " 이름 나이 : ";
        cin >> name >> age;
        p[i].set(name, age);
    }

    // 4) 각 배열원소를 인자로 showPersonByValue 함수를 호출하여 이름과 나이가 출력되도록 함(복사생성자와 소멸자 호출됨)
    for (int i = 0; i < n; i++)
    {
        showPersonByValue(p[i]);
    }

    // 5) 각 배열원소를 인자로 showPersonByRef 함수를 호출하여 이름과 나이가 출력되도록 함(복사생성자와 소멸자 호출안됨)
    for (int i = 0; i < n; i++)
    {
        showPersonByRef(p[i]);
    }

    // 6) 동적 배열을 반납
    delete[] p;

    cout << "-------------------------------" << endl;
}