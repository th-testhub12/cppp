#include <iostream>
#include <string>
#include "Circle.cpp"
using namespace std;

void increase(Circle c)
{
}
int main()
{
    Circle src(30);
    Circle dest(src);
    increase(src); //얘도 복사생성자 호출
    cout << "src.getArea() = " << src.getArea() << endl;
    cout << "dest.getArea() = " << dest.getArea() << endl;
}
