#include <iostream>
using namespace std;

class Circle
{
private:
    int radius;

public:
    Circle(const Circle &c) //왜 &c 에서 참조를 빼면 복사 생성자 호출 과정에서 복사가 일어남
    {
        //이제 컴파일러가 복사 생성자 제공 X
        cout << (this->radius = c.radius) << " 복사 생성" << endl;
    };
    Circle() { cout << (radius = 1) << " 생성\n"; }
    Circle(int r) { cout << (radius = r) << " 생성\n"; }
    ~Circle() { cout << radius << " 소멸\n"; }
    double getArea() { return 3.14 * radius * radius; }
    int getRadius() { return radius; }
    void setRadius(int r) { radius = r; }
};
// Book 복사 생성자