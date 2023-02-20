#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>

// #define a 10 //无参宏
// #define name "afvsdhg"


using namespace std;

struct Node
{
    int val;
    Node* next;
    Node(int x) : val(x), next(nullptr) {}
};
class student
{
public:
    int a, b;
    student() {
        cout << "student构造~" << endl;
    }
    virtual void print() {
        cout << "I am a student" << endl;
    }
    void add(int a, int b) {
        cout << a + b << endl;
    }
    void add(int a, int b, int c) { //重载
        cout << a + b + c << endl;
    }

    virtual ~student() {
        cout << "~析构student" << endl;
    }
};

class KK : public student
{
public:
    KK() {
        cout << "KK构造~" << endl;
    }
    void print() { //覆盖
        cout << "I am KK" << endl;
    }
    void add(int a, int b) { //
        cout << a - b << endl;
    }
    void add(int a, int b, int c, int d) { //重定义
        cout << a + b + c + d << endl;
    }
    ~KK() {
        cout << "~析构KK" << endl;
    }
};


int main() {
    //虚函数的调用取决于指向或者引用的对象的类型，而不是指针或者引用自身的类型
    // student *kk = new KK(); //基类函数若不声明为virtual，在调用函数时取决于指针类型，否则取决于指针指向的对象类型
    // kk->print();
    //student *st = &kk;
    KK kk;
    kk.add(1,1);
    kk.add(1,1,1,1);
    student *st = &kk;
    st->print();
    st->add(1,1);
    st->add(1,1,1);
    //st->add(1,1,1,1);
    


    return 0;
}

