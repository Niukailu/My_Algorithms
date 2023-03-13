#include <iostream>
#include <stdlib.h>
#include <memory>
#include <vector>

using namespace std;

class Monster
{
public:
    weak_ptr<Monster> m_father;
    weak_ptr<Monster> m_son;

    void setFather(shared_ptr<Monster>& father) {
        m_father = father;
    }
    void setSon(shared_ptr<Monster>& son) {
        m_son = son;
    }
    ~Monster() {
        cout << "die~" << endl;
    }
};


int main() {
    shared_ptr<Monster> s = make_shared<Monster>();

    unique_ptr<Monster> a(new Monster);
    unique_ptr<Monster> b(a.release());
    



    return 0;
}