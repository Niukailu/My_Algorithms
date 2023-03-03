#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>

using namespace std;

void reverseS(string& s, int begin, int end) {
    for (int i = begin, j = end; i < j; i++, j--)
    {
        swap(s[i], s[j]);    
    }
}
string reverseWords2(string s) { //写的太复杂了。。
    int n = s.length();
    reverseS(s, 0, n - 1);
    int i = 0;
    int cnt = 0;
    for (int j = 0; j < n; j++)
    {
        if(s[j] == ' ') {
            if(i == j) ++i;
            else {
                reverseS(s, i, j - 1);
                cnt++;
                i = j + 1;
            }
        }
    }
    if(i < n) reverseS(s, i, n - 1), cnt++;
    int left = 0, right = 0;
    int cnum = 0;
    while (right < n)
    {
        if(s[right] != ' ') {
            s[left++] = s[right];
            cnum++;
            if(right + 1 < n && s[right + 1] == ' ') s[left++] = ' ';
        }
        ++right;
    }
    s.resize(cnum + cnt - 1);
    return s;
}
string reverseWords(string s) {
    int start = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if(s[i] != ' ') {
            if(start != 0) s[start++] = ' ';
            while (i < s.length() && s[i] != ' ') s[start++] = s[i++];
        }
    }
    s.resize(start);
    reverseS(s, 0, s.length() - 1);
    start = 0;
    for (int i = 0; i <= s.length(); i++)
    {
        if(i == s.length() || s[i] == ' ') {
            reverseS(s, start, i - 1);
            start = i + 1;
        }
    }
    return s;
}
//KMP
void getnext(vector<int>& next, string& s) {
    int i = 0;
    for (int j = 1; j < s.length(); j++)
    {
        if(s[i] == s[j]) i++;
        else {
            while (i > 0 && s[i] != s[j])
            {
                i = next[i - 1];
            }
            if(s[i] == s[j]) i++;
        }
        next[j] = i;
    }
}
int strStr(string haystack, string needle) { 
    int m = haystack.length(), n = needle.length();
    vector<int> next(n, 0);
    getnext(next, needle);
    int i = 0, j = 0;
    while (i < m && j < n)
    {
        if(haystack[i] == needle[j]) j++;
        else {
            while (j > 0 && haystack[i] != needle[j])
            {
                j = next[j - 1];
            }
            if(haystack[i] == needle[j]) j++;
        }
        i++;
    }
    return j == n ? i - j : -1;
}


int main() {
    string s = "bvjnfn";
    s.reserve(10);
    cout << s[9] << endl;
    //cout << sizeof(s) << " " << s.capacity() << endl;


    return 0;
}