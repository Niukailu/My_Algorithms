#include <bits/stdc++.h>

using namespace std;

long long beautifulSubarrays(vector<int>& nums) {
    long long res = 0;
    unordered_map<int, int> umap;
    umap[0] = 1;
    int pre = 0;
    for(int& num : nums) {
        pre ^= num;
        if(umap.count(pre)) res += umap[pre];
        umap[pre]++;
    }
    return res;
}

bool times[2001] = {0};

int findMinimumTime(vector<vector<int>>& tasks) {
    sort(tasks.begin(), tasks.end(), [](auto& a, auto& b) {
        return a[1] < b[1];
    });
    int res = 0;
    for(auto& it : tasks) {
        int d = it[2];
        for (int i = it[0]; i <= it[1]; i++)
        {
            if(times[i]) --d;
        }
        for (int i = it[1]; d > 0; i--)
        {
            if(!times[i]) {
                ++res;
                times[i] = true;
                --d;
            }
        }
    }
    return res;
}


int main() {
    int n;
    scanf("%d", &n);
    
    

    return 0;
}