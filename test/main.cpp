#include <iostream>
#include "a.h"
#include <stdlib.h>

using namespace std;

typedef struct node
{
    int val;
    node *next;
    node(int x) : val(x), next(nullptr) {}
}SBOX;

SBOX *n1 = new SBOX(10);
//SBOX n2 = {11, &n1};
SBOX *n3 = n1;

int *k = (int *)malloc(sizeof(SBOX) * 10);

void func1(int num) {
    int a[num];
    a[1] = 100;
    cout << a[0] << " " << a[1] << endl;
}

int getnum(int a) {
    return a * a;
}

int add(volatile int *a) {
    return *a * *a;
}

int main(int argc, char *argv[]) {
    int b = 10;
    int *a = &b;
    cout << add(a) << endl;
    

    return 0;
}