#include <bits/stdc++.h>

using namespace std;

class B;

class A
{
private:
	int age = 10;
	static int cnt;
public:
	static void fun1() {
		
	}
	void print(int age) {
		cnt++;
		cout << this->cnt << endl;
		this->age = age;
		cout << this->age << endl;
	}
	friend class B;
};

int A::cnt = 0;

class B
{
public:
	void print2(A a, int age) {
		a.age = age;
		cout << a.age << endl;
	}

	void print3(A a, int age) {
		a.age = age;
		cout << a.age << endl;
	}
};



int main()
{
	A a;
	a.print(1);
	A aa;
	aa.print(2);



	return 0;
}