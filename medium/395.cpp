#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

//分治
int dfs(string& s, int& k, int left, int right) {
    if(right - left + 1 < k) return 0;
    int counts[26] = {0};
    for (int i = left; i <= right; i++) ++counts[s[i] - 'a'];
    unordered_set<char> lessk;
    for (int i = 0; i < 26; i++)
    {
        if(counts[i] && counts[i] < k) lessk.insert('a' + i);
    }
    if(lessk.size() == 0) return right - left + 1;
    int maxlen = 0, prelen = 0;
    for (int i = left; i <= right; i++) {
        if(!lessk.count(s[i])) ++prelen;
        else {
            maxlen = max(maxlen, dfs(s, k, i - prelen, i - 1));
            prelen = 0;
        }
    }
    if(prelen) maxlen = max(maxlen, dfs(s, k, right + 1 - prelen, right));
    return maxlen;
}
int longestSubstring(string s, int k) {
    return dfs(s, k, 0, s.length() - 1);    
}

//KMP(复习)
void getnext(vector<int>& next, string& needle) {
    int j = 0;   //j指向前缀末尾
    for (int i = 1; i < needle.size(); i++) //i指向后缀末尾
    {
        while (j > 0 && needle[i] != needle[j])
        {
            j = next[j - 1];
        }
        if(needle[i] == needle[j]) ++j;
        next[i] = j;
    }
}
int strStr(string haystack, string needle) {
    int m = haystack.length(), n = needle.length();
    if(n > m) return -1;
    vector<int> next(n, 0);
    getnext(next, needle);
    int i = 0, j = 0;
    while (i < m && j < n)
    {
        if(haystack[i] == needle[j]) ++i, ++j;
        else {
            if(j > 0) j = next[j - 1];
            else ++i;
        }
    }
    return j == n ? i - j : -1;
}