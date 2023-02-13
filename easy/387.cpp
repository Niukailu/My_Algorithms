#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int firstUniqChar(string s) {
    int chars[26] = {0};
    int idxes[26] = {-1};
    for (int i = 0; i < s.size(); i++)
    {
        ++chars[s[i] - 'a'];
        if(chars[s[i] - 'a'] == 1) idxes[s[i] - 'a'] = i;
    }
    int res = INT32_MAX;
    for (int i = 0; i < 26; i++)
    {
        if(chars[i] == 1) res = min(res, idxes[i]);
    }
    return res == INT32_MAX ? -1 : res;
}

//快速幂
long long fpow(long long x, long long n) {
    long long res = 1;
    while (n)
    {
        if(n % 2 == 0) {
            x *= x;
            n /= 2;
        }
        else {
            res *= x;
            --n;
        }
    }
    return res;
}
long long fpow(long long x, long long n) { //精简版
    long long res = 1;
    while (n)
    {
        if(n & 1) res *= x;
        n >>= 1;
        x *= x;
    }
    return res;
}