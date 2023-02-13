#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

//对我太难了。。前后缀分解
int minimumScore(string s, string t) {
    int m = s.length(), n = t.length();
    vector<int> prelen(m + 1, 0);
    for (int i = 0, j = 0; i < m; i++)
    {
        if(j < n && s[i] == t[j]) prelen[i + 1] = prelen[i] + 1, ++j;
        else prelen[i + 1] = prelen[i];
    }
    vector<int> suflen(m + 1, 0);
    for (int i = m - 1, j = n - 1; i >= 0; i--)
    {
        if(j >= 0 && s[i] == t[j]) suflen[i] = suflen[i + 1] + 1, --j;
        else suflen[i] = suflen[i + 1];
    }
    int maxlen = 0;
    for (int i = 0; i <= m; i++)
    {
        maxlen = max(maxlen, min(n, prelen[i] + suflen[i]));
    }
    return n - maxlen;
}