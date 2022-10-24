#include <iostream>
using namespace std;

class Rect
{
private:
    int width, height;

public:
    Rect(int w, int h)
    {
        this->width = w;
        this->height = h;
    }
    friend bool equal(Rect a, Rect b);
};

bool equal(Rect a, Rect b)
{
    if (a.width == b.width && a.height == b.height)
        return true;
    else
        return false;
}

int main()
{
    Rect a(3, 4), b(5, 6);
    if (equal(a, b))
        cout << "equal" << endl;
    else
        cout << "not equal" << endl;
}