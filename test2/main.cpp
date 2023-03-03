#include <iostream>
#include <stdlib.h>
//#include "test.cpp"
#include <thread>
#include <atomic>

using namespace std;

/*
class Shape //抽象类
{
public:
    virtual int getArea() = 0; //纯虚函数
    void setWidth(int w) {
        width = w;
    }
    void setHeight(int h) {
        height = h;
    }

protected:
    int width;
    int height;
};

class Rectangle: public Shape
{
public:
    int getArea() {
        return width * height;
    }
};
*/

int main() {  
    //若子类没有定义构造函数，则默认调用父类的无参数（有参则编译报错）的构造方法
    //如果父类只有有参数的构造方法，则子类必须显示调用此带参构造方法 
    //子类和父类中有同名成员，子类成员将屏蔽父类对同名成员的直接访问，这种情况叫隐藏，也叫重定义 
    // person a(20, "niu");
    // a.print(); //只能访问本类的public成员
    
    int *a = new int(10);
    int *b = a;
    delete a;
    cout << *b << endl;
    
    
    return 0;
}