#include <iostream>
#include <stdio.h>
using namespace std;
 
class Test
{
public:
	Test(int a, int b, int c) : 
		m_a(a),
		m_b(b),
		m_c(c)
	{
		m = a + b + c;
	}
 
	void Show()
	{
		cout << "m = " << m << endl;
	}
 
private:
	int m_a, m_b, m_c;
	static int m;
};
 
int Test::m = 0; //初始化静态数据成员
 
int main()
{
	Test ClassA(1, 1, 1);
	ClassA.Show();  //输出: 3
	Test ClassB(3, 3, 3);
	ClassB.Show(); //输出: 9
	ClassA.Show(); //输出: 9
 
	system("pause");
	return 0;
}