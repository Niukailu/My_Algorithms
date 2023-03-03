#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

vector<int> divisibilityArray(string word, int m) {
    vector<int> res(word.length(), 0);
    long long pre = 0;
    for (int i = 0; i < word.length(); i++)
    {
        pre = (pre * 10 + (word[i] - '0')) % m;
        res[i] = pre ? 0 : 1;
    }
    return res;
}

int maxNumOfMarkedIndices(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int i = 0, j = (nums.size() + 1) / 2; //尽量和最后面的部分匹配
    for (; j < nums.size(); j++)
    {
        if(2 * nums[i] <= nums[j]) ++i;
    }
    return 2 * i;       
}

int minimumTime(vector<vector<int>>& grid) {
    if(grid[0][1] > 1 && grid[1][0] > 1) return -1;
    int m = grid.size(), n = grid[0].size();
    priority_queue<pair<int, pair<int, int>>> que;
    que.push({0, {0, 0}});
    vector<vector<bool>> vis(m, vector<bool>(n, false));
    int dirs[4][2] = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};
    while (!que.empty())
    {
        auto item = que.top();
        que.pop();
        int i = item.second.first, j = item.second.second;
        if(vis[i][j]) continue;
        vis[i][j] = true;
        if(i == m - 1 && j == n - 1) return -item.first;
        for (int k = 0; k < 4; k++)
        {
            int ii = i + dirs[k][0];
            int jj = j + dirs[k][1];
            if(ii >= 0 && ii < m && jj >= 0 && jj < n && !vis[ii][jj]) {
                if(1 - item.first >= grid[ii][jj]) que.push({item.first - 1, {ii, jj}});
                else if((grid[ii][jj] + item.first) % 2) que.push({-grid[ii][jj], {ii, jj}});
                else que.push({-grid[ii][jj] - 1, {ii, jj}});
            }
        } 
    }
    return -1;
}
//71. 简化路径
string simplifyPath(string path) {
    path += '/';
    stack<string> ss;
    string s = "";
    for (int i = 1; i < path.length(); i++)
    {
        if(path[i] == '/') {
            if(path[i - 1] != '/' && s != "") {
                if(s == "..") {
                    if(!ss.empty()) ss.pop(); 
                }
                else if(s != ".") ss.push(s);
                s = ""; 
            }
        }
        else s += path[i];
    }
    string res = "";
    while (!ss.empty())
    {
        res = "/" + ss.top() + res;
        ss.pop();
    }
    return res == "" ? "/" : res;
}

int main() {
    string p = "/a//b////c/d//././/..";
    cout << simplifyPath(p) << endl;


    return 0;
}