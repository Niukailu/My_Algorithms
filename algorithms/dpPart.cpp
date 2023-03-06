#include <bits/stdc++.h>

using namespace std;

int minCostClimbingStairs(vector<int>& cost) {
    int first = 0, sceond = 0;
    for (int i = 2; i <= cost.size(); i++)
    {
        int next = min(first + cost[i - 2], sceond + cost[i - 1]);
        first = sceond;
        sceond = next;
    }
    return sceond;
}

int uniquePaths(int m, int n) {
    vector<int> dp(n, 1);
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++) {
            dp[j] += dp[j - 1];
        }
    }
    return dp[n - 1];
}

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size(), n = obstacleGrid[0].size();
    vector<int> dp(n, 0);
    for (int j = 0; j < n; j++)
    {
        if(obstacleGrid[0][j]) break;
        dp[j] = 1;
    }
    for (int i = 1; i < m; i++)
    {
        if(obstacleGrid[i][0]) dp[0] = 0;
        for (int j = 1; j < n; j++)
        {
            if(obstacleGrid[i][j]) dp[j] = 0;
            else dp[j] += dp[j - 1];
        }
    }
    return dp[n - 1];
}

int integerBreak(int n) {
    vector<int> dp(n + 1, 0);
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            dp[i] = max(dp[i], max(j * (i - j), j * dp[i - j]));
        } 
    }
    return dp[n];
}

int numTrees(int n) {
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            dp[i] += dp[j - 1] * dp[i - j];
        }
    }
    return dp[n];
}







int main() {



    return 0;
}
