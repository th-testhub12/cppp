// p.335
#include <iostream>
using namespace std;

class Power
{
private:
    int kick, punch;

public:
    Power(int kick = 0, int punch = 0)
    {
        this->kick = kick;
        this->punch = punch;
    }
    ~Power()
    {
    }
    void show()
    {
        cout << "Kick: " << kick << ", Punch: " << punch << endl;
    }
    Power operator+(const Power &op2) //참조로 선언하는 것이 바람직
    {
        Power tmp;
        tmp.kick = this->kick + op2.kick;
        tmp.punch = this->punch + op2.punch;
        return tmp; //값 복사하여 return하고 tmp는 소멸
    }
    Power operator+(int op2)
    {
        Power tmp;
        tmp.kick = this->kick + op2;
        tmp.punch = this->punch + op2;
        return tmp;
    }
    bool operator==(const Power &op2)
    {
        if (kick == op2.kick && punch == op2.punch)
            return true;
        return false;
    }
    bool operator<(const Power &op2)
    {
        if (kick * kick + punch * punch < op2.kick * op2.kick + op2.punch * op2.punch)
            return true;
        return false;
    }
    bool operator>(const Power &op2)
    {
        if (this->operator<(op2) == false)
            return true;
        return false;
    }

    // p.351 예제    외부함수를 friend로 선언
    friend Power operator+(int op1, const Power &op2);
};

// **************외부함수 추가**************
// void operator+(Power &op1, int op2)
// {
//     op1.kick += op2;
//     op1.punch += op2;
// }
Power operator+(int op1, const Power &op2)
{
    Power tmp;
    tmp.kick = op1 + op2.kick;
    tmp.punch = op1 + op2.punch;
    return tmp;
}

int main()
{
    Power a(3, 5), b(4, 6), c;
    a.show();
    b.show();
    c = a + b; // c = a.operator+(b);
    c.show();
    c = a + 7; // c = a.operator+(7);
    c.show();
    c = 7 + a; // c = operator+(7, a);
    c.show();
    cout << (a.operator==(b)) << endl;
    if (a < b)
        cout << "a < b" << endl;
    else
        cout << "a >= b" << endl;
    if (c > b)
        cout << "c > b" << endl;
    else
        cout << "c <= b" << endl;
}