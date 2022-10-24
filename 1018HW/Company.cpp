#include <iostream>
#include <string>

using namespace std;

class Company
{
private:
    string name;
    int capital;

public:
    Company() : Company("", 0) {}

    Company(string name, int capital)
    {
        this->name = name;
        this->capital = capital;
    }

    ~Company()
    {
    }

    string getName()
    {
        return this->name;
    }

    void show()
    {
        cout << "회사명 = " << this->name << ", 자본금 = " << this->capital << endl;
    }

    Company operator+(const Company &c)
    {
        Company temp;
        if (this->capital >= c.capital)
        {
            temp.name = this->name;
            temp.capital = this->capital + c.capital;
        }
        else
        {
            temp.name = c.name;
            temp.capital = this->capital + c.capital;
        }
        return temp;
    }

    Company operator*(int multiple)
    {
        Company temp;
        temp.name = this->name;
        temp.capital = this->capital * multiple;
        return temp;
    }

    friend Company operator*(int a, const Company &c);

    bool operator<(const Company &c)
    {
        if (this->capital < c.capital)
            return true;
        else
            return false;
    }
};

Company operator*(int a, const Company &c)
{
    Company temp;
    temp.name = c.name;
    temp.capital = c.capital * a;
    return temp;
}

int main()
{
    Company a("Oracool", 300), b("SunMacro", 200), c("Golgol", 600);

    a.show();
    b.show();
    c.show();

    a = a + b;
    a.show();

    a = a * 2;
    a.show();

    c = 2 * c;
    c.show();

    if (a < c)
        cout << a.getName() << " < " << c.getName() << endl;
    else
        cout << a.getName() << " >= " << c.getName() << endl;
}