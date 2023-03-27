#include <bits/stdc++.h>

using namespace std;


string minWindow(string S, string T) {
    unordered_map<char, int> umap;
    unordered_set<char> uset;
    for(char& c : T) {
        umap[c]++;
        uset.emplace(c);
    }
    int res = INT32_MAX;
    int begin = 0;
    int left = 0, right = 0;
    while (right < S.length())
    {
        if(umap.count(S[right])) {
            umap[S[right]]--;
            if(umap[S[right]] == 0) uset.erase(S[right]);
        }
        while (uset.size() == 0 && left <= right)
        {
            if(right - left + 1 < res) {
                res = right - left + 1;
                begin = left;
            }
            if(umap.count(S[left])) {
                umap[S[left]]++;
                if(umap[S[left]] > 0) uset.emplace(S[left]);
            }
            left++;
        }
        right++;
    }
    return res == INT32_MAX ? "" : S.substr(begin, res);
}

bool dfs(vector<int>& arr, int start, unordered_set<int>& uset) {
    if(arr[start] == 0) return true;
    if(uset.count(start)) return false;
    uset.emplace(start);
    if(start + arr[start] < arr.size()) {
        if(dfs(arr, start + arr[start], uset)) return true;
    }
    if(start - arr[start] >= 0) {
        if(dfs(arr, start - arr[start], uset)) return true;
    }
    return false;
}
bool canReach(vector<int>& arr, int start) {
    unordered_set<int> uset;
    return dfs(arr, start, uset);
}

int longestPalindromeSubseq(string s) {
    int len = s.length();
    vector<vector<int>> dp(len, vector<int>(len, 0));
    for (int i = len - 1; i >= 0; i--)
    {
        for (int j = i; j < len; j++)
        {
            if(i == j) dp[i][j] = 1;
            else {
                if(s[i] == s[j]) dp[i][j] = dp[i - 1][j - 1] + 2;
                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[len - 1][len - 1];
}


bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    stack<int> stk;
    int start = 0;
    for (int i = 0; i < popped.size(); i++)
    {
        if(!stk.empty() && popped[i] == stk.top()) stk.pop();
        else {
            while(start < pushed.size() && pushed[start] != popped[i]) {
                stk.push(pushed[start++]);
            }
            start++;
            if(start > pushed.size()) return false;
        }
    }
    return true;
}