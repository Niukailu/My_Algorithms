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

int main()
{
   char a[10];
   strcpy2(a, "aaaaa");
   printf(a);
   

   return 0;
}