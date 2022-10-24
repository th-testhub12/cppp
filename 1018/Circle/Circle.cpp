#include <iostream>
using namespace std;

class Circle
{
private:
    static int numOfCircles;
    int radius;

public:
    Circle(int r = 1)
    {
        numOfCircles++;
        this->radius = 1;
    }
    ~Circle()
    {
        numOfCircles--;
    }
    double getRadius()
    {
        numOfCircles = 1; // non-static 멤버 함수는 static 접근 가능
        return radius;
    }
    static int getNumOfCircles()
    {
        this->radius = 0; // static 멤버는 this 도 사용 불가능
        // radius = 0; //어떤 객체의 반지름을 접근하려는건데??? -> static 함수는 non-static 멤버 접근 불가 ->
        return numOfCircles;
    }
};

int Circle::numOfCircles = 0;

int main()
{
    Circle *p = new Circle[10];
    cout << Circle::getNumOfCircles() << endl;
    delete[] p;
    cout << Circle::getNumOfCircles() << endl;

    Circle a;
    cout << Circle::getNumOfCircles() << endl;

    Circle b;
    cout << Circle::getNumOfCircles() << endl;
}