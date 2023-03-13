#include <iostream>
#include <vector>

using namespace std;

int longestPalindrome(string s) {
    int len = s.length();
    vector<vector<int>> dp(len, vector<int>(len, 0));
    int res = 0;
    for (int i = len - 1; i >= 0; i--)
    {
        for (int j = i; j < len; j++)
        {
            if(s[i] == s[j]) {
                if(i == j) dp[i][j] = 1;
                else if(j == i + 1) dp[i][j] = 2;
                else {
                    if(dp[i + 1][j - 1]) dp[i][j] = dp[i + 1][j - 1] + 2;
                }
            }
            cout << dp[i][j] << " ";
            res = max(res, dp[i][j]);
        }
        cout << endl;
    }
    return res;
}

int main() {
    string s = "abcbaaa";
    cout << longestPalindrome(s) << endl; 


    return 0;
}