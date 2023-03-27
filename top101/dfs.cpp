#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> permutes;
vector<int> item;
void dfs(vector<int> &num, vector<bool>& flags) {
    if(item.size() == num.size()) {
        permutes.push_back(item);
        return;
    }
    for (int i = 0; i < num.size(); i++)
    {
        if(!flags[i]) {
            flags[i] = true;
            item.push_back(num[i]);
            dfs(num, flags);
            flags[i] = false;
            item.pop_back();
        }
    }
}
vector<vector<int>> permute(vector<int> &num) {
    vector<bool> flags(num.size(), false);
    dfs(num, flags);
    return permutes;
}

void bfs(vector<vector<char>>& grid, int i, int j, int& m, int& n) {
    grid[i][j] = '0';
    if(i - 1 >= 0 && grid[i - 1][j] == '1') bfs(grid, i - 1, j, m, n);
    if(i + 1 < m && grid[i + 1][j] == '1') bfs(grid, i + 1, j, m, n);
    if(j - 1 >= 0 && grid[i][j - 1] == '1') bfs(grid, i, j - 1, m, n);
    if(j + 1 < n && grid[i][j + 1] == '1') bfs(grid, i, j + 1, m, n);
}

int solve(vector<vector<char>>& grid) {
    if(grid.size() == 0) return 0;
    int m = grid.size(), n = grid[0].size();
    int num = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(grid[i][j] == '1') {
                num++;
                bfs(grid, i, j, m, n);
            }
        }
    }
    return num;
}

vector<string> strs;
string s = "";
void getstrP(string& str, vector<bool>& flags) {
    if(s.length() == str.length()) {
        strs.push_back(s);
        return;
    }
    unordered_set<char> uset;
    for (int i = 0; i < str.length(); i++)
    {
        if(flags[i] || uset.count(str[i])) continue;
        uset.emplace(str[i]);
        flags[i] = true;
        s += str[i];
        getstrP(str, flags);
        flags[i] = false;
        s.pop_back();
    }
}

vector<string> Permutation(string str) {
    vector<bool> flags(str.length(), false);
    getstrP(str, flags);
    return strs;
}

vector<string> kuohaos;
void getkuohao(int& n, int left, int right, string kh) {
    if(left == n && right == n) {
        kuohaos.push_back(kh);
        return;
    }
    if(left < n) getkuohao(n, left + 1, right, kh + '(');
    if(right < left) getkuohao(n, left, right + 1, kh + ')');
}

vector<string> generateParenthesis(int n) {
    if(n == 0) return {};
    getkuohao(n, 1, 0, "(");
    return kuohaos;
}


int memo[1010][1010];
int get_solve(vector<vector<int>>& matrix, int i, int j) {
    if(memo[i][j]) return memo[i][j];
    int down = 0;
    if(i + 1 < matrix.size() && matrix[i][j] < matrix[i + 1][j]) {
        down = memo[i + 1][j] = get_solve(matrix, i + 1, j);
    }
    int up = 0;
    if(i - 1 >= 0 && matrix[i][j] < matrix[i - 1][j]) {
        up = memo[i - 1][j] = get_solve(matrix, i - 1, j);
    }
    int right = 0;
    if(j + 1 < matrix[0].size() && matrix[i][j] < matrix[i][j + 1]) {
        right = memo[i][j + 1] = get_solve(matrix, i, j + 1);
    }
    int left = 0;
    if(j - 1 >= 0 && matrix[i][j] < matrix[i][j - 1]) {
        left = memo[i][j - 1] = get_solve(matrix, i, j - 1);
    }
    memo[i][j] = max(up, max(down, max(left, right))) + 1;
    return memo[i][j];
}

int solve(vector<vector<int>>& matrix) { // 矩阵最长递增路径 (dfs + 记忆化)
    int maxlen = 0;
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            maxlen = max(maxlen, get_solve(matrix, i, j));
        }
    }
    return maxlen;
}


