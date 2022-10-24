#include <iostream>
#include <string>
using namespace std;

void half(double &n)
{
    n /= 2;
}

bool bigger(int a, int b, int &big)
{
    if (a == b)
    {
        big = a;
        return true;
    }
    else if (a > b)
        big = a;
    else
        big = b;
    return false;
}

int main()
{
    double n = 20.0;
    half(n);
    cout << n << endl;

    int a, b, c;
    cout << "2개의 정수를 입력하시오" << endl;
    cin >> a >> b;
    if (bigger(a, b, c))
        cout << "두 수가 같음, ";
    cout << "큰 수는 " << c << endl;
}
