#include <bits/stdc++.h>

using namespace std;


string fun1(string s) {
    int num = 2;
    int left = 0, right = s.length() - 1;
    while (left < right)
    {
        if(s[left] != s[right]) {
            s[left] = min(s[left], s[right]);
            s[right] = min(s[left], s[right]);
            num--;
            if(num == 0) break;
        }
        left++, right--;
    }
    left = 0, right = s.length() - 1;
    while (left <= right && num > 0)
    {
        if(s[left] != 'a') {
            if(left != right && num == 2) {
                s[left] = 'a';
                s[right] = 'a';
                num -= 2;
            }
            else if(left == right) {
                s[left] = 'a';
                num--;
            }
        }
        left++, right--;
    }
    return s;
}

//i个商品中，买j个商品，用k个券，所花的最少钱数
int dp[110][110][55];
vector<int> fun2(vector<vector<int>> goods, int x, int y) {
    int n = goods.size();
    int max_num = 0, min_money = INT32_MAX;
    for (int i = 1; i <= n; i++) 
    {
        for (int j = 1; j <= i; j++)
        {
            for (int k = 0; k < min(j, y); k++)
            {
                //不买这个
                if(i - 1 >= j) dp[i][j][k] = dp[i - 1][j][k];
                else dp[i][j][k] = INT32_MAX;
                //原价买这个
                if(j - 1 >= k) dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j - 1][k] + goods[i - 1][0]);
                //折扣价买这个
                if(k > 0) dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j - 1][k - 1] + goods[i - 1][1]);
                //如果钱数够买，更新结果
                if(x >= dp[i][j][k]) {
                    if(j > max_num) { //优先商品数量最大
                        max_num = j;
                        min_money = dp[i][j][k];
                    }
                    else if(j == max_num) { //再使得花钱最少
                        min_money = dp[i][j][k];
                    }
                }
            }
        }
    }
    vector<int> res;
    res.push_back(max_num);
    res.push_back(min_money);
    return res;
}

int fun3(vector<int> colors, int k) {
    int res = 0;
    unordered_map<int, int> umap;
    int left = 0;
    for (int i = 0; i < colors.size(); i++)
    {
        umap[colors[i]]++;
        while (umap.size() > k)
        {
            umap[colors[left]]--;
            if(umap[colors[left]] == 0) umap.erase(colors[left]);
            left++;
        }
        res = max(res, i - left + 1);
    }
    return res;
}

//二维前缀和
int pre[1010][1010];
int fun4(vector<vector<int>> army, int a, int b) {
    for(auto& it : army) {
        pre[it[0]][it[1]]++;
    }
    for (int i = 1; i <= 1000; i++)
    {
        for (int j = 1; j <= 1000; j++)
        {
            pre[i][j] = pre[i][j] + pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1];
        }
    }
    int res = 0;
    for (int i = 1; i <= 1000; i++)
    {
        for (int j = 1; j <= 1000; j++)
        {
            int ii = max(0, i - a - 1);
            int jj = max(0, j - b - 1);
            res = max(res, pre[i][j] - pre[ii][j] - pre[i][jj] + pre[ii][jj]);
        }
    }
    return res;
}

int energy[510];
unordered_map<int, vector<int>> umap;
void dfs(int root, int last, int dist) {
    if(dist == 0) return;
    for(auto& it : umap[root]) {
        if(it == last) continue;
        energy[it]++;
        dfs(it, root, dist - 1);
    }
}
vector<int> fun5(vector<int> dists, vector<vector<int>> edges) {
    for(auto& it : edges) {
        umap[it[0]].push_back(it[1]);
        umap[it[1]].push_back(it[0]);
    }
    int n = dists.size();
    for (int i = 1; i <= n; i++)
    {
        dfs(i, -1, dists[i - 1]);
    }
    vector<int> res;
    for (int i = 1; i <= n; i++)
    {
        res.push_back(energy[i]);
    }
    return res;
}

//欧拉筛
vector<int> getPrim(int n) {
    vector<int> prims;
    vector<bool> vis(n + 1, false);
    for (int i = 2; i <= n; i++)
    {
        if(!vis[i]) prims.push_back(i);
        for(int& p : prims) {
            if(p > n / i) break;
            vis[p * i] = true;
            if(i % p == 0) break;
        }
    }
    return prims;
}

int main() {





    return 0;
}

