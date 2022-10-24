#include <iostream>
using namespace std;

class Circle
{
private:
    int radius;

public:
    Circle() { cout << (radius = 1) << " 생성\n"; }
    Circle(int r) { cout << (radius = r) << " 생성\n"; }
    ~Circle() { cout << radius << " 소멸\n"; }
    double getArea() { return 3.14 * radius * radius; }
    int getRadius() { return radius; }
    void setRadius(int r) { radius = r; }
};
