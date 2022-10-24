#include <iostream>
#include <string>
#include "Circle.cpp"
using namespace std;

void increase(Circle &c)
{
    int r = c.getRadius();
    c.setRadius(r + 1);
}

int main()
{
    Circle pizza(30);
    cout << "Before INCREASE: " << pizza.getRadius() << endl;
    increase(pizza); //주소값 전달(&pizza, *c, c->get) OR 참조 선언(pizza, &c, c.get) / 참조가 훨씬 간편하다, 매개변수만 참조 선언을 하면 끝이기 때문이다.
    //값에 의한 increase 호출 시에는 컴파일러가 자동으로 복사 생성자 제공
    cout << "After INCREASE: " << pizza.getRadius() << endl;
}