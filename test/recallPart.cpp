#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>

using namespace std;

int findnum(vector<int>& nums, int val) {//找最左边的目标值
    int left = 0, right = nums.size() - 1;
    int mid = 0;
    while (left <= right)
    {
        mid = left + ((right - left) >> 1);
        if(val > nums[mid]) left = mid + 1;
        else right = mid - 1;
    }
    if(left >= nums.size()) return -1;
    return nums[left] == val ? left : -1;
}
int hannuota(int n) {
    vector<int> dp(n + 1, 0);
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = 2 * dp[i - 1] + 1;
    }
    return dp[n];
}
int hannuota2(int n) { // A-->B
    vector<int> dp1(n + 1, 0);
    vector<int> dp2(n + 1, 0);
    dp1[1] = 1;
    dp2[1] = 2;
    for (int i = 2; i <= n; i++)
    {
        dp1[i] = 2 * dp2[i - 1] + 1;
        dp2[i] = 2 * dp2[i - 1] + dp1[i - 1] + 2;
    }
    return dp1[n];
    // return dp2[n];  A-->C
}
//
vector<vector<int>> combineRes;
void getCombine(vector<int> item, int begin, int& n, int& k) {
    if(n - begin + 1 < k) return;
    if(item.size() == k) {
        combineRes.push_back(item);
        return;
    }
    for (int i = begin; i <= n; i++)
    {
        item.push_back(i);
        getCombine(item, i + 1, n, k);
        item.pop_back();
    }
}
vector<vector<int>> combine(int n, int k) {
    getCombine({}, 1, n, k);
    return combineRes;
}
vector<vector<int>> combineSum;
void findSum(vector<int> item, int& k, int n, int start) {
    if(item.size() == k) {
        if(n == 0) combineSum.push_back(item);
        return;
    }
    if(n < start) return;
    for (int i = start; i <= 9; i++)
    {
        item.push_back(i);
        findSum(item, k, n - i, i + 1);
        item.pop_back();
    }
}
vector<vector<int>> combinationSum3(int k, int n) {
    findSum({}, k, n, 1);
    return combineSum;
}
//
vector<vector<int>> combSum;
void findComb(vector<int> item, vector<int>& candidates, int target, int start) {
    if(target == 0) {
        combSum.push_back(item);
        return;
    }
    if(target < candidates[start]) return;
    for (int i = start; i < candidates.size(); i++)
    {
        item.push_back(candidates[i]);
        findComb(item, candidates, target - candidates[i], i);
        item.pop_back();
    }
}
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    findComb({}, candidates, target, 0);
    return combSum;   
}
//分割回文串
bool isright(string& s) {
    for (int i = 0, j = s.length() - 1; i < j; i++, j--)
    {
        if(s[i] != s[j]) return false;
    }
    return true;
}
vector<vector<string>> plans;
void getplans(string& s, vector<string> plan, int start) {
    if(start == s.length()) {
        plans.push_back(plan);
        return;
    }
    for (int i = start; i < s.length(); i++)
    {
        if(s[start] != s[i]) continue;
        string part = s.substr(start, i - start + 1); 
        if(isright(part)) {  //可以动规预处理s
            plan.push_back(part);
            getplans(s, plan, i + 1);
            plan.pop_back();
        }
    }
}
vector<vector<string>> partition(string s) {
    getplans(s, {}, 0);
    return plans;
}
//递增子序列(set去重)
vector<vector<int>> seqs;
void findseqs(vector<int>& nums, vector<int>& item, int start) {
    if(item.size() >= 2) {
        seqs.push_back(item);
    }
    unordered_set<int> uset; //同层去重
    for (int i = start; i < nums.size(); i++)
    {
        if((!item.empty() && nums[i] < item.back()) || uset.count(nums[i])) continue;
        uset.emplace(nums[i]);
        item.push_back(nums[i]);
        findseqs(nums, item, i + 1);
        item.pop_back();
    }
}
vector<vector<int>> findSubsequences(vector<int>& nums) {
    vector<int> item;
    findseqs(nums, item, 0);
    return seqs;
}
//全排列
vector<vector<int>> perms;
vector<int> item;
void findperms(vector<int>& nums, vector<bool>& vis) {
    if(item.size() == nums.size()) perms.push_back(item); 
    for (int i = 0; i < nums.size(); i++)  //排列问题，每次都要从头开始搜索
    {
        if(vis[i]) continue;
        vis[i] = true;   //同一树枝去重
        item.push_back(nums[i]);
        findperms(nums, vis);
        item.pop_back();
        vis[i] = false;
    }
}
vector<vector<int>> permute(vector<int>& nums) {
    vector<bool> vis(nums.size(), false);
    findperms(nums, vis);
    return perms;
}
//全排列2
vector<vector<int>> permsUniq;
vector<int> item;
void findpermsUniq(vector<int>& nums, vector<bool>& vis) {
    if(item.size() == nums.size()) permsUniq.push_back(item); 
    //int flags[21] = {0}; //同层去重
    for (int i = 0; i < nums.size(); i++)  //排列问题，每次都要从头开始搜索
    {
        if(i > 0 && nums[i] == nums[i - 1] && !vis[i - 1]) continue; //同层去重(需排序)
        if(vis[i]) continue;   //同枝去重
        //flags[nums[i] + 10] = 1;
        vis[i] = true;   
        item.push_back(nums[i]);
        findpermsUniq(nums, vis);
        item.pop_back();
        vis[i] = false;
    }
}
vector<vector<int>> permuteUnique(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<bool> vis(nums.size(), false);
    findpermsUniq(nums, vis);
    return permsUniq;
}
//332. 重新安排行程
unordered_map<string, map<string, int>> umap;
vector<string> travel;
bool findtravel(vector<vector<string>>& tickets, string start) {
    if(travel.size() == tickets.size() + 1) return true;
    if(umap.count(start)) {
        for(auto& it : umap[start]) {
            if(it.second > 0) {
                travel.push_back(it.first);
                it.second--;
                if(findtravel(tickets, it.first)) return true;
                travel.pop_back();
                it.second++;
            }
        }
    }
    return false;
}
vector<string> findItinerary(vector<vector<string>>& tickets) {
    for(auto& it : tickets) {
        umap[it[0]][it[1]]++;
    }
    travel.push_back("JFK");
    findtravel(tickets, "JFK");
    return travel;
}
//n皇后
vector<vector<string>> solvers;
bool judge(int i, int j, vector<string>& item) {
    for (int row = 0; row < i; row++)
    {
        if(item[row][j] == 'Q') return false;
    }
    for (int r = i, c = j; r >= 0 && c >= 0; r--, c--)
    {
        if(item[r][c] == 'Q') return false;
    }
    for (int r = i, c = j; r >= 0 && c < item.size(); r--, c++)
    {
        if(item[r][c] == 'Q') return false;
    }
    return true;
}
void findsolvers(int& n, int i, vector<string>& item) {
    if(i == n) {
        solvers.push_back(item);
        return;
    }
    for (int j = 0; j < n; j++)
    {
        if(judge(i, j, item)) {
            item[i][j] = 'Q';
            findsolvers(n, i + 1, item);
            item[i][j] = '.';
        }
    }
}
vector<vector<string>> solveNQueens(int n) {
    vector<string> item(n, string(n, '.'));
    findsolvers(n, 0, item);
    return solvers;
}
//解数独
bool judge(vector<vector<char>>& board, int i, int j, char c) {
    for (int row = 0; row < 9; row++)
    {
        if(board[row][j] == c) return false;
    }
    for (int col = 0; col < 9; col++)
    {
        if(board[i][col] == c) return false;
    }
    int num1 = (i / 3) * 3;
    int num2 = (j / 3) * 3;
    for (int row = num1; row < num1 + 3; row++)
    {
        for (int col = num2; col < num2 + 3; col++)
        {
            if(board[row][col] == c) return false;
        }
    }
    return true;
}
bool findsolution(vector<vector<char>>& board, int idx) {
    if(idx == 81) return true;
    int i = idx / 9, j = idx % 9;
    if(board[i][j] != '.') return findsolution(board, idx + 1);
    for (int k = 1; k <= 9; k++)
    {
        char c = '0' + k;
        if(judge(board, i, j, c)) {
            board[i][j] = c;
            if(findsolution(board, idx + 1)) return true;
            board[i][j] = '.';
        }
    }
    return false;
}
void solveSudoku(vector<vector<char>>& board) {
    findsolution(board, 0);
}


int main() {
    

    return 0;
}