#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
using namespace std;

class Book
{
private:
    char *title;
    int price;

public:
    Book(const char *title, int price)
    {
        int len = strlen(title);
        this->title = new char[len + 1];
        strcpy(this->title, title);
        this->price = price;
    }
    Book(const Book &book)
    {
        int len = strlen(book.title);
        this->title = new char[len + 1];
        strcpy(this->title, book.title);
        this->price = book.price;
    }
    ~Book()
    {
        if (this->title)
            delete[] this->title;
    }
    void set(const char *title, int price)
    {
        if (this->title)
            delete[] this->title;
        int len = strlen(title);
        this->title = new char[len + 1];
        strcpy(this->title, title);
        this->price = price;
    }
    void show()
    {
        cout << this->title << ", " << this->price << "원" << endl;
    }
};

int main()
{
    Book cpp("명품 C++", 10000);
    Book java = cpp; // Book java(cpp);
    java.set("명품 JAVA", 12000);
    cpp.show();
    java.show();
}