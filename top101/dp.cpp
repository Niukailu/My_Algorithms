#include <bits/stdc++.h>

using namespace std;

string LCS(string s1, string s2) {
    int len1 = s1.length(), len2 = s2.length();
    vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
    for (int i = 1; i <= len1; i++) {
        for (int j = 1; j <= len2; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } 
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    string s = "";
    int i = len1, j = len2;
    while (dp[i][j] > 0)
    {
        if(s1[i - 1] == s2[j - 1]){
            s += s1[i - 1];
            i--, j--;
        }
        else if(dp[i - 1][j] > dp[i][j - 1]) i--;
        else j--;
    }
    reverse(s.begin(), s.end());
    return s;
}

string LCS2(string str1, string str2) {
    int len1 = str1.length(), len2 = str2.length();
    vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
    int maxlen = 0, begin = 0;
    for (int i = 1; i <= len1; i++)
    {
        for (int j = 1; j <= len2; j++)
        {
            if(str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            if(dp[i][j] > maxlen) {
                maxlen = dp[i][j];
                begin = i - 1;
            }
        }
    }
    return str1.substr(begin, maxlen);
}

int minPathSum(vector<vector<int> >& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));
    dp[0][0] = matrix[0][0];
    for(int i = 1; i < m; i++) dp[i][0] = dp[i - 1][0] + matrix[i][0];
    for(int j = 1; j < n; j++) dp[0][j] = dp[0][j - 1] + matrix[0][j];
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + matrix[i][j];
        }
    }
    return dp[m - 1][n - 1];
}

int solve(string nums) {
    int len = nums.length();
    if (len == 0) return 0;
    vector<int> dp(len + 1, 0);
    dp[0] = 1;
    if (nums[0] != '0') dp[1] = 1;
    for (int i = 2; i <= len; i++) {
        if (nums[i - 1] == '0') {
            if (nums[i - 2] > '0' && nums[i - 2] < '3') dp[i] = dp[i - 2];
        } else {
            dp[i] = dp[i - 1];
            int num = (nums[i - 2] - '0') * 10 + (nums[i - 1] - '0');
            if (num >= 10 && num <= 26) dp[i] += dp[i - 2];
        }
    }
    return dp[len];
}

int minMoney(vector<int>& arr, int aim) {
    vector<int> dp(aim + 1, -1);
    dp[0] = 0;
    for (int i = 1; i <= aim; i++)
    {
        for (int j = 0; j < arr.size(); j++)
        {
            if(i >= arr[j] && dp[i - arr[j]] != -1)  {
                if(dp[i] == -1) dp[i] = dp[i - arr[j]] + 1;
                else dp[i] = min(dp[i], dp[i - arr[j]] + 1);
            } 
        }
    }
    return dp[aim];
}

int LIS(vector<int>& arr) {
    if(arr.size() == 0) return 0;
    vector<int> dp(arr.size(), 1);
    int res = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            if(arr[i] > arr[j]) dp[i] = max(dp[i], dp[j] + 1);
        }
        res = max(res, dp[i]);
    }
    return dp[arr.size() - 1];
}

int FindGreatestSumOfSubArray(vector<int> array) {
    int pre = 0, res = INT32_MIN;
    for(int& it : array) {
        if(pre < 0) pre = it;
        else pre += it;
        res = max(res, pre);
    }
    return res;
}

vector<string> res;
void dfs(string& s, string item, int n, int start) {
    if(start == s.length()) {
        if(n == 4) {
            item.pop_back();
            res.push_back(item);
        }
        return;
    }
    if(s.length() - start < n) return;
    int num = 0;
    for (int i = start; i < start + 3 && i < s.length(); i++)
    {
        if(i > start && s[start] == '0') break;
        num = num * 10 + (s[i] - '0');
        if(num >= 0 && num <= 255) {
            dfs(s, item + s.substr(start, i - start + 1) + '.', n + 1, i + 1);
        }
    }
}
vector<string> restoreIpAddresses(string s) {
    if(s.length() < 4) return {};
    dfs(s, "", 0, 0);
    return res;
}

int editDistance(string str1, string str2) {
    int len1 = str1.length(), len2 = str2.length();
    vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
    for(int i = 1; i <= len1; i++) dp[i][0] = dp[i - 1][0] + 1;
    for(int j = 1; j <= len2; j++) dp[0][j] = dp[0][j - 1] + 1;
    for (int i = 1; i <= len1; i++)
    {
        for (int j = 1; j <= len2; j++)
        {
            if(str1[i - 1] == str2[j - 1]) dp[i][j] = dp[i - 1][j - 1];
            else {
                dp[i][j] = min(dp[i][j - 1], min(dp[i - 1][j], dp[i - 1][j - 1])) + 1;
            }
        }
    }
    return dp[len1][len2];
}

bool match(string str, string pattern) {
    vector<string> pat;
    for(int i = 0; i < pattern.length(); i++) {
        if(i + 1 < pattern.length() && pattern[i + 1] == '*') {
            pat.push_back(pattern.substr(i, 2));
            i++;
        }
        else pat.push_back(pattern.substr(i, 1));
    }
    int len1 = str.length(), len2 = pat.size();
    vector<vector<bool>> dp(len1 + 1, vector<bool>(len2 + 1, false));
    dp[0][0] = true;
    for (int j = 1; j <= len2; j++)
    {
        if(pat[j - 1].length() == 2 && dp[0][j - 1]) dp[0][j] = true; 
    }
    for (int i = 1; i <= len1; i++)
    {
        for (int j = 1; j <= len2; j++)
        {
            if(dp[i - 1][j - 1]) {
                if(pat[j - 1][0] == '.' || pat[j - 1][0] == str[i - 1]) dp[i][j] = true;
            }
            if(dp[i][j - 1]) {
                if(pat[j - 1].length() == 2) dp[i][j] = true;
            }
            if(dp[i - 1][j]) {
                if(pat[j - 1].length() == 2 && (pat[j - 1][0] == '.' || pat[j - 1][0] == str[i - 1])) dp[i][j] = true;
            }
        }
    }
    return dp[len1][len2];
}

int longestValidParentheses(string s) {
    stack<int> stk;
    stk.push(-1);
    int res = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if(s[i] == ')') {
            if(stk.top() != -1 && s[stk.top()] == '(') {
                stk.pop();
                res = max(res, i - stk.top());
            } 
            else stk.push(i);
        }
        else stk.push(i);
    }
    return res;
}

int robb(vector<int>& nums, int left, int right) {
    if(left == right) return nums[left];
    int len = right - left + 1;
    vector<int> dp(len, 0);
    dp[0] = nums[left];
    dp[1] = max(nums[left], nums[left + 1]);
    for (int i = 2; i < len; i++)
    { 
        dp[i] = max(dp[i - 2] + nums[left + i], dp[i - 1]);
    }
    return dp[len - 1]; 
}

int rob(vector<int>& nums) { 
    if(nums.size() == 1) return nums[0];   
    int left = robb(nums, 0, nums.size() - 2);
    int right = robb(nums, 1, nums.size() - 1);
    return max(left, right);
}

int maxProfit(vector<int>& prices) {
    if(prices.size() < 2) return 0;
    vector<vector<int>> dp(prices.size(), vector<int>(5, 0));
    dp[0][1] = dp[0][3] = -prices[0];
    for (int i = 1; i < prices.size(); i++)
    {
        dp[i][1] = max(dp[i - 1][0] - prices[i], dp[i - 1][1]);
        dp[i][2] = max(dp[i - 1][1] + prices[i], dp[i - 1][2]);
        dp[i][3] = max(dp[i - 1][2] - prices[i], dp[i - 1][3]);
        dp[i][4] = max(dp[i - 1][3] + prices[i], dp[i - 1][4]);
    }
    return max(dp[prices.size() - 1][2], dp[prices.size() - 1][4]);
}



