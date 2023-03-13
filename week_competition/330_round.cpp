#include <bits/stdc++.h>

using namespace std;

long long mod = 1e9 + 7;
long long quickPow(int xx, int n) {
    long long res = 1;
    long long x = xx;
    while (n)
    {
        if(n & 1) res = (res * x) % mod;
        n /= 2;
        x = (x * x) % mod;
    }
    return res;
}
int monkeyMove(int n) {
    return (quickPow(2, n) - 2 + mod) % mod;
}

long long putMarbles(vector<int>& weights, int k) {
    vector<long long> nums;
    for (int i = 0; i < weights.size() - 1; i++)
    {
        nums.push_back((long long)weights[i] + weights[i + 1]);
    }
    sort(nums.begin(), nums.end());
    long long mini = 0;
    for (int i = 0; i < k - 1; i++) mini += nums[i];
    long long maxi = 0;
    for (int i = 0; i < k - 1; i++) maxi += nums[nums.size() - 1 - i];
    return maxi - mini;
}


int main() {



    return 0;
}