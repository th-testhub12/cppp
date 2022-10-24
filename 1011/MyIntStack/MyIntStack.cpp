#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
// #include <cstring>
using namespace std;

class MyIntStack
{
private:
    int *p; //배열 크기 = size
    int size;
    int tos; //데이터를 push 할 위치(index) == 데이터 개수
public:
    MyIntStack() : MyIntStack(10) {}
    MyIntStack(int size)
    {
        this->tos = 0;
        this->size = size;
        this->p = new int[this->size];
    }
    MyIntStack(const MyIntStack &stack)
    {
        this->tos = stack.tos;
        this->size = stack.size;
        this->p = new int[this->size];
        for (int i = 0; i < stack.tos; i++)
        {
            this->p[i] = stack.p[i];
        }
    }
    ~MyIntStack()
    {
        if (this->p)
            delete[] this->p;
    }
    bool push(int n)
    {
        if (tos == this->size)
            return false;
        p[tos++] = n; // p[tos] = n; tos++;
        return true;
    }
    bool pop(int &n)
    {
        if (tos == 0)
            return false;
        n = p[--tos];
        return true;
    }
};

int main()
{
    int size;
    // cout << "INPUT SIZE: ";
    // cin >> size;
    MyIntStack a(5);
    for (int i = 0; i < 12; i++)
    {
        if (a.push(i))
            cout << i << " IS PUSHED   ";
        else
        {
            cout << "i=" << i << ",ALREADY FULL   ";
            break;
        }
    }
    cout << endl;
    MyIntStack b(a);
    int n;
    cout << "A: ";
    for (int i = 0; i < 12; i++)
    {
        if (a.pop(n))
            cout << n << " IS POPPED   ";
        else
        {
            cout << "i=" << i << ",ALREADY EMPTY   ";
            break;
        }
    }
    cout << endl
         << "B: ";
    for (int i = 0; i < 12; i++)
    {
        if (b.pop(n))
            cout << n << " IS POPPED   ";
        else
        {
            cout << "i=" << i << ",ALREADY EMPTY   ";
            break;
        }
    }
}