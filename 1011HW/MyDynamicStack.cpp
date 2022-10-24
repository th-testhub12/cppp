#include <iostream>
using namespace std;

class MyDynamicStack
{
private:
    int *p;   //동적 배열
    int size; //배열의 크기
    int tos;  //배열의 위치 및 데이터 개수

public:
    // Stack() : Stack(4) {}
    MyDynamicStack()
    {
        this->p = new int[4];
        this->size = 4;
        this->tos = 0;
    }
    MyDynamicStack(int size)
    {
        this->p = new int[size];
        this->size = size;
        this->tos = 0;
    }
    MyDynamicStack(const MyDynamicStack &stack)
    {
        this->size = stack.size;
        this->tos = stack.tos;
        this->p = new int[stack.size];
        for (int i = 0; i < stack.size; i++)
        {
            this->p[i] = stack.p[i];
        }
    }
    ~MyDynamicStack()
    {
        if (this->p)
            delete[] this->p;
    }
    bool push(int n)
    {
        if (tos == this->size)
        {
            this->size *= 2;
            int *q = new int[this->size];
            if (p == NULL)
                return false;
            for (int i = 0; i < this->size / 2; i++)
            {
                q[i] = this->p[i];
            }
            delete[] p;
            p = q;
        }

        p[tos++] = n;
        return true;
    }
    bool pop(int &n)
    {
        if (tos == 0)
            return false;
        n = this->p[--tos]; // pop 먼저 실행하고 배열 크기 축소

        if (tos == this->size / 2 && this->size > 4)
        {
            this->size /= 2;
            int *q = new int[this->size];
            for (int i = 0; i < this->size; i++)
            {
                q[i] = this->p[i];
            }
            delete[] p;
            p = q;
        }

        return true;
    }
    int length()
    {
        return this->tos;
    }
    int getSize()
    {
        return this->size;
    }
};

int main()
{
    int item;

    // Stack a에 8개 push
    MyDynamicStack a;
    cout << "a 처음: size = " << a.getSize() << " length = " << a.length() << endl;
    for (int i = 1; i <= 8; i++)
        if (a.push(i))
            cout << "a " << i << " push 성공: size = " << a.getSize() << " length = " << a.length() << endl;
    cout << endl;

    // Stack copy에 8개 추가 push
    MyDynamicStack copy(a);
    cout << "copy 처음: size = " << copy.getSize() << " length = " << copy.length() << endl;
    for (int i = 9; i <= 16; i++)
        if (copy.push(i))
            cout << "copy " << i << " push 성공: size = " << copy.getSize() << " length = " << copy.length() << endl;
    cout << endl;

    // Stack a에서 9개 pop
    for (int i = 1; i <= 9; i++)
        if (a.pop(item))
            cout << "a " << item << " pop성공: size = " << a.getSize() << " length = " << a.length() << endl;
    cout << endl;

    // Stack copy에서 17개 pop
    for (int i = 1; i <= 17; i++)
        if (copy.pop(item))
            cout << "copy " << item << " pop 성공: size = " << copy.getSize() << " length = " << copy.length() << endl;
    cout << endl;
}