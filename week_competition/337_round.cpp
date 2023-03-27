#include <bits/stdc++.h>

using namespace std;


int findSmallestInteger(vector<int>& nums, int value) {
    vector<int> taps(value, 0);
    for (int i = 0; i < nums.size(); i++)
    {
        taps[(nums[i] % value + value) % value]++;
    }
    int mini = INT32_MAX, num = 0;
    for (int i = 0; i < value; i++)
    {
        if(mini == 0) break;
        if(taps[i] < mini) {
            mini = taps[i];
            num = i;
        }
    }
    return mini * value + num;
}

int cnt = -1;
int flags[1001];
void dfs(vector<int>& nums, const int k, int start) {
    cnt++;
    for (int i = start; i < nums.size(); i++)
    {
        if(nums[i] - k < 0 || flags[nums[i] - k] == 0) {
            flags[nums[i]]++;
            dfs(nums, k, i + 1);
            flags[nums[i]]--;
        }
    }
}
int beautifulSubsets(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    dfs(nums, k, 0);
    return cnt;
}

int maximizeGreatness(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    priority_queue<int, vector<int>, greater<int>> que(nums.begin(), nums.end());
    int res = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        while (!que.empty() && que.top() <= nums[i])
        {
            que.pop();
        }
        if(!que.empty()) {
            que.pop();
            res++;
        }
        if(que.empty()) break;
    }
    return res;
}

typedef long long ll;
ll getnum(vector<int>& ranks, ll mid) {
    ll res = 0;
    for (int i = 0; i < ranks.size(); i++)
    {
        res += sqrt(mid / ranks[i]);
    }
    return res;
}
long long repairCars(vector<int>& ranks, int cars) {
    ll left = 1, right = 1e14;
    while (left < right)
    {
        ll mid = left + (right - left) / 2;
        ll num = getnum(ranks, mid);
        if(num >= cars) right = mid;
        else left = mid + 1;
    }
    return left;  
}


int main() {
    vector<int> nums = {10,4,5,7,2,1};
    beautifulSubsets(nums, 3);

    return 0;
}