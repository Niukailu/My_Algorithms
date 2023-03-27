#include <bits/stdc++.h>

using namespace std;

char* strcpy2(char* dest, const char* src) {
   assert(dest != nullptr && src != nullptr);
   char* ret = dest;
   while (true)
   {
      *dest = *src;
      if(*src == '\0') break;
      dest++;
      src++;
   }
   
   return ret;
}

class a
{
public:
   int cnt = 0;
   void fun1() {
      ++cnt;
   }
   void fun2() const {
      
   }
};

int main()
{
   int n = 1;
   for (int i = 0; i < 3; i++)
   {
      [n] () mutable {
         ++n;
         cout << n << endl;
      }();
   }
   
   cout << n << endl;



   return 0;
}