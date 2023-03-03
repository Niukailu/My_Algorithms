#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
#include <list>
using namespace std;

int findContentChildren(vector<int>& g, vector<int>& s) {
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int res = 0;
    int i = 0, j = 0;
    while (i < g.size() && j < s.size())
    {
        if(s[j] >= g[i]) {
            res++;
            i++;
        }
        else j++;
    }
    return i;
}
int wiggleMaxLength(vector<int>& nums) {//动规
    int len = nums.size();
    vector<vector<int>> dp(len, vector<int>(2, 0));
    dp[0][0] = 1, dp[0][1] = 1;
    for (int i = 1; i < len; i++)
    {
        dp[i][0] = dp[i][1] = 1;
        for (int j = 0; j < i; j++)
        {
            if(nums[i] > nums[j]) dp[i][0] = max(dp[i][0], dp[j][1] + 1);
            if(nums[i] < nums[j]) dp[i][1] = max(dp[i][1], dp[j][0] + 1);
        }
    }
    return max(dp[len - 1][0], dp[len - 1][1]);
}
int wiggleMaxLength2(vector<int>& nums) {//贪心
    int len = nums.size();
    if(len < 2) return len;
    int up = 1, down = 1;
    for (int i = 1; i < len; i++)
    {
        if(nums[i] > nums[i - 1]) up = down + 1;
        if(nums[i] < nums[i - 1]) down = up + 1;
    }
    return max(up, down); 
}
int maxSubArray(vector<int>& nums) {
    int maxsum = nums[0], pre = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        if(pre < 0) pre = nums[i];
        else pre += nums[i];
        maxsum = max(maxsum, pre);
    }
    return maxsum;
}
int maxProfit(vector<int>& prices) {
    if(prices.size() < 2) return 0;
    int res = 0;
    for (int i = 1; i < prices.size(); i++)
    {
        if(prices[i] > prices[i - 1]) res += prices[i] - prices[i - 1];
    }
    return res;
}
bool canJump(vector<int>& nums) {
    int pre = 1;
    for (int i = 0; i < nums.size(); i++)
    {
        if(pre <= 0) return false;
        pre = max(pre - 1, nums[i]);
    }
    return true;
}
int jump(vector<int>& nums) {
    int cnt = 0;
    int cover = 0, end = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        cover = max(cover, nums[i] + i);
        if(i == end) {
            if(i == nums.size() - 1) return cnt;
            cnt++;
            end = cover;
        }
    }
    return cnt;
}
int largestSumAfterKNegations(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    int sum = 0, minnum = INT32_MAX;
    for (int i = 0; i < nums.size(); i++)
    {
        if(nums[i] < 0 && k > 0) {
            nums[i] = -nums[i];
            --k;
        }
        sum += nums[i];
        minnum = min(minnum, nums[i]);
    }
    if(k % 2) sum -= 2 * minnum;
    return sum;
}
int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int len = gas.size();
    int begin = 0, pre = -1;
    for (int i = 0; i < 2 * len; i++)
    {
        if(begin >= len) return -1;
        int now = gas[i % len] - cost[i % len];
        if(pre < 0) {
            begin = i;
            pre = now;
        }
        else {
            if(i != begin && i % len == begin) return begin;
            pre += now;
        }
    }
    return -1;
}
int candy(vector<int>& ratings) {
    vector<int> candies(ratings.size(), 1);
    for (int i = 1; i < ratings.size(); i++)
    {
        if(ratings[i] > ratings[i - 1]) candies[i] = candies[i - 1] + 1;
    }
    int sum = candies[ratings.size() - 1];
    for (int i = ratings.size() - 2; i >= 0; i--)
    {
        if(ratings[i] > ratings[i + 1]) candies[i] = max(candies[i], candies[i + 1] + 1);
        sum += candies[i];
    }
    return sum;
}
/*
static bool cmp(const vector<int>& a, const vector<int>& b) {
    if(a[0] == b[0]) return a[1] < b[1];
    return a[0] > b[0];
}
vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
    sort(people.begin(), people.end(), cmp);
    list<vector<int>> res;
    for (int i = 0; i < people.size(); i++)
    {
        int idx = people[i][1];
        auto it = res.begin();
        while(idx--) it++;
        res.insert(it, people[i]);
    }
    return vector<vector<int>>(res.begin(), res.end());
}
*/
static bool cmp(const vector<int>& a, const vector<int>& b) {
    if(a[0] == b[0]) return a[1] < b[1];
    return a[0] < b[0];
}
int findMinArrowShots(vector<vector<int>>& points) {
    sort(points.begin(), points.end(), cmp);
    int res = 1;
    int right = points[0][1];
    for (int i = 1; i < points.size(); i++)
    {
        if(points[i][0] > right) {
            res++;
            right = points[i][1];
        }
        else right = min(right, points[i][1]);
    }
    return res;
}
int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(), cmp);
    int res = 0;
    int right = intervals[0][1];
    for (int i = 1; i < intervals.size(); i++)
    {
        if(intervals[i][0] < right) {
            res++;
            right = min(right, intervals[i][1]);
        }
        else {
            right = intervals[i][1];
        }
    }
    return res;
}
vector<int> partitionLabels(string s) {
    vector<int> dics(26, 0);
    for (int i = 0; i < s.length(); i++)
    {
        dics[s[i] - 'a'] = i;
    }
    int left = -1, right = 0;
    vector<int> res;
    for (int i = 0; i < s.length(); i++)
    {
        right = max(right, dics[s[i] - 'a']);
        if(i == right) {
            res.push_back(right - left);
            left = i;
        }
    }
    return res;
}
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(), cmp);
    int left = intervals[0][0], right = intervals[0][1];
    vector<vector<int>> res;
    for (int i = 1; i < intervals.size(); i++)
    {
        if(intervals[i][0] <= right) {
            right = max(right, intervals[i][1]);
        }
        else {
            res.push_back({left, right});
            left = intervals[i][0];
            right = intervals[i][1];
        }
    }
    res.push_back({left, right});
    return res;
}
//968. 监控二叉树
struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
int res = 0;
int dfs(TreeNode* root) {
    if(!root) return 1;
    int l = dfs(root->left);
    int r = dfs(root->right);
    if(l == 0 || r == 0) {
        res++;
        return 2;
    }
    else if(l == 2 || r == 2) return 1;
    else return 0;
}
int minCameraCover(TreeNode* root) {
    if(dfs(root) == 0) res++;
    return res;
}



