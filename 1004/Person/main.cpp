#include <iostream>
#include <string>
#include "Person.cpp"
using namespace std;

int main()
{
    int n;
    string name;
    int age;
    cout << "n의 값을 입력하시오" << endl;
    cin >> n;
    Person *p = new Person[n];
    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << " 번째 사람의 이름과 나이를 입력하시오" << endl;
        cin >> name >> age;
        p[i].set(name, age);
    }
    cout << "20살 이상인 사람: ";
    for (int i = 0; i < n; i++)
    {
        if (p[i].getAge() >= 20)
        {
            cout << p[i].getName() << " ";
        }
    }
    cout << endl;
    delete[] p;
}