#include <bits/stdc++.h>
using namespace std;

void dfs1(unordered_map<int, vector<int>>& tree, map<pair<int, int>, int>& mp, int last, int now, int& cnt) {
    for(auto& it : tree[now]) {
        if(it == last) continue;
        if(mp.count({now, it})) cnt++;
        dfs1(tree, mp, now, it, cnt);
    }
}
int res = 0;
void dfs2(unordered_map<int, vector<int>>& tree, map<pair<int, int>, int>& mp, int last, int now, int cnt, int& k) {
    if(cnt >= k) res++;
    for(auto& it : tree[now]) {
        if(it == last) continue;
        dfs2(tree, mp, now, it, cnt - mp[{now, it}] + mp[{it, now}], k);
    }
}
int rootCount(vector<vector<int>>& edges, vector<vector<int>>& guesses, int k) {
    unordered_map<int, vector<int>> tree;
    for(auto& it : edges) {
        tree[it[0]].push_back(it[1]);
        tree[it[1]].push_back(it[0]);
    }    
    map<pair<int, int>, int> mp;
    for(auto& it : guesses) {
        mp[{it[0], it[1]}]++;
    }
    int cnt = 0;
    dfs1(tree, mp, -1, 0, cnt);
    dfs2(tree, mp, -1, 0, cnt, k);
    return res;
}


int main() {



    return 0;
}