#include <iostream>
#include "Person.cpp"
using namespace std;

int main()
{
    Person father(1, "Kitae");
    Person daughter(father);
    father.show();
    daughter.show();
    cout << endl;
    daughter.changeName("Grace");
    father.show();
    daughter.show();
}