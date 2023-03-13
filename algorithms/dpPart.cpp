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

bool canPartition(vector<int>& nums) {
    int sum = 0;
    for (int i = 0; i < nums.size(); i++) sum += nums[i];
    if(sum % 2) return false;
    sum /= 2;
    vector<int> dp(sum + 1, 0);
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = sum; j >= nums[i]; j--) {
            dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
        }
    }
    return dp[sum] == sum;
}

int lastStoneWeightII(vector<int>& stones) {
    int sum = 0;
    for (int i = 0; i < stones.size(); i++) sum += stones[i];
    int left = sum / 2;
    vector<int> dp(left + 1, 0);
    for (int i = 0; i < stones.size(); i++)
    {
        for (int j = left; j >= stones[i]; j--) {
            dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
        }
    }
    return sum - 2 * dp[left];
}

int findTargetSumWays(vector<int>& nums, int target) {
    int sum = 0;
    for(int i = 0; i < nums.size(); i++) sum += nums[i];
    if((sum + target) % 2) return 0;
    if(abs(target) > sum) return 0;
    int left = (sum + target) / 2;
    vector<int> dp(left + 1, 0);
    dp[0] = 1;
    for(int i = 0; i < nums.size(); i++) {
        for(int j = left; j >= nums[i]; j--) {
            dp[j] += dp[j - nums[i]];
        }
    }
    return dp[left];

}

int findMaxForm(vector<string>& strs, int m, int n) {
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < strs.size(); i++)
    {
        int num0 = 0, num1 = 0;
        for(char& c : strs[i]) {
            if(c == '0') num0++;
            else num1++;
        }
        for (int j = m; j >= num0; j--)
        {
            for (int z = n; z >= num1; z--)
            {
                dp[j][z] = max(dp[j][z], dp[j - num0][z - num1] + 1);
            }
        }
    }
    return dp[m][n];
}

int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, INT32_MAX);
    dp[0] = 0;
    for(int i = 0; i < coins.size(); i++) {
        for(int j = coins[i]; j <= amount; j++) {
            if(dp[j - coins[i]] != INT32_MAX) dp[j] = min(dp[j], dp[j - coins[i]] + 1);
        }
    }
    return dp[amount] == INT32_MAX ? -1 : dp[amount];
}

bool wordBreak(string s, vector<string>& wordDict) {
    int len = s.length();
    vector<bool> dp(len + 1, false);
    dp[0] = true;
    for(int i = 1; i <= len; i++) {
        for(int j = 0; j < wordDict.size(); j++) {
            if(dp[i]) break;
            int l = wordDict[j].length();
            if(i >= l && s.substr(i - l, l) == wordDict[j] && dp[i - l]) dp[i] = true;
        }
    }
    return dp[len];
}

int rob(vector<int>& nums) {
    vector<int> dp(nums.size(), 0);
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);
    for (int i = 2; i < nums.size(); i++)
    {
        dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
    }
    return dp[nums.size() - 1];
}

int maxProfit(vector<int>& prices) { //309. 最佳买卖股票时机含冷冻期
    int len = prices.size();
    vector<vector<int>> dp(len, vector<int>(3, 0));
    dp[0][1] = -prices[0];
    for(int i = 1; i < prices.size(); i++) {
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
        dp[i][1] = max(dp[i - 1][1], dp[i - 1][2] - prices[i]);
        dp[i][2] = max(dp[i - 1][2], dp[i - 1][0]);
    }
    return dp[len - 1][0];
}

int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) { //1035. 不相交的线
    int len1 = nums1.size(), len2 = nums2.size();
    vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
    for(int i = 1; i <= len1; i++) {
        for(int j = 1; j <= len2; j++) {
            if(nums1[i - 1] == nums2[j - 1]) {
                dp[i][j] = dp[i - 1][j  -1] + 1;
            }
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[len1][len2];
}


int main() {



    return 0;
}
