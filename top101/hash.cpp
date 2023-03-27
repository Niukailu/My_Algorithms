#include <bits/stdc++.h>

using namespace std;

int MoreThanHalfNum_Solution(vector<int> numbers) {
    if(numbers.size() == 0) return 0;
    int res = numbers[0];
    int cnt = 1;
    for (int i = 1; i < numbers.size(); i++)
    {
        if(numbers[i] == res) ++cnt;
        else --cnt;
        if(cnt == 0) {
            res = numbers[i];
            cnt = 1;
        }
    }
    return res;
}

vector<int> FindNumsAppearOnce(vector<int>& array) { //只出现一次的两个数字
    int xor_num = 0;
    for(int& it : array) {
        xor_num ^= it;
    }
    int fact = 1;
    while(xor_num & fact == 0) fact <<= 1;
    int a = 0, b = 0;
    for(int& it : array) {
        if(it & fact) a ^= it;
        else b ^= it;
    }
    vector<int> res;
    res.push_back(a);
    res.push_back(b);
    if(res[0] > res[1]) swap(res[0], res[1]);
    return res;
}

int minNumberDisappeared(vector<int>& nums) {
    int len = nums.size();
    for (int i = 0; i < len; i++)
    {
        while (nums[i] > 0 && nums[i] <= len && nums[nums[i] - 1] != nums[i])
        {
            swap(nums[i], nums[nums[i] - 1]);
        }
    }
    int res = 1;
    while (nums[res - 1] == res) ++res;
    return res;
}

vector<vector<int>> threeSum(vector<int> &num) {
    sort(num.begin(), num.end());
    vector<vector<int>> res;
    for (int i = 0; i < num.size(); i++)
    {
        if(i > 0 && num[i] == num[i - 1]) continue;
        if(num[i] > 0) break;
        int left = i + 1, right = num.size() - 1;
        while (left < right)
        {
            int sum = num[i] + num[left] + num[right];
            if(sum < 0) ++left;
            else if(sum > 0) --right;
            else {
                res.push_back({num[i], num[left], num[right]});
                while(left + 1 < right && num[left + 1] == num[left]) ++left;
                ++left;
                while(right - 1 > left && num[right -1] == num[right]) --right;
                --right;
            }
        }
    }
    return res;   
}




int main() {
    



    return 0;
}