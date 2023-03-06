#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> umap;
    for(string& s : strs) {
        string tmp = s;
        sort(tmp.begin(), tmp.end());
        umap[tmp].push_back(s);
    }
    vector<vector<string>> res;
    for(auto& it : umap) {
        res.push_back(it.second);
    }
    return res;
}
vector<int> findAnagrams(string s, string p) {
    if(s.length() < p.length()) return {};
    unordered_map<char, int> umap;
    unordered_set<char> uset;
    for(char& c : p) {
        umap[c]++;
        uset.emplace(c);
    }
    vector<int> res;
    int i = 0, j = 0;
    while (j < s.length())
    {
        if(umap.count(s[j])) {
            umap[s[j]]--;
            if(umap[s[j]] == 0) uset.erase(s[j]);
        }
        j++;
        while (j - i >= p.length())
        {
            if(uset.size() == 0) res.push_back(i);
            if(umap.count(s[i])) { //固定窗口，每次只需要收缩一位
                umap[s[i]]++;
                if(umap[s[i]] > 0) uset.emplace(s[i]);
            }
            i++;
        }
    }
    return res;
}
//两数之和
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> umap;
    for (int i = 0; i < nums.size(); i++)
    {
        int tmp = target - nums[i];
        if(umap.count(tmp)) return {umap[tmp], i};
        else umap[nums[i]] = i;
    }
    return {-1, -1};     
}
int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
    unordered_map<int, int> umap;
    for (int i = 0; i < nums1.size(); i++)
    {
        for (int j = 0; j < nums2.size(); j++)
        {
            umap[nums1[i] + nums2[j]]++;
        }
    }
    int cnt = 0;
    for (int k = 0; k < nums3.size(); k++)
    {
        for (int l = 0; l < nums4.size(); l++) {
            int target = 0 - nums3[k] - nums4[l];
            if(umap.count(target)) cnt += umap[target];
        }
    } 
    return cnt;
}
vector<vector<int>> threeSum(vector<int>& nums) { // 三数之和 哈希法
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    int n = nums.size();
    if(nums[0] > 0 || nums[n - 1] < 0) return res;
    unordered_map<int, int> umap;
    for (int i = 0; i < nums.size(); i++) umap[nums[i]] = i;
    for (int i = 0; i < nums.size(); i++)
    {
        if(nums[i] > 0) break;
        if(i > 0 && nums[i] == nums[i - 1]) continue;
        for (int j = i + 1; j < nums.size(); j++)
        {
            if(nums[i] + nums[j] > 0) break;
            if(j > i + 1 && nums[j] == nums[j - 1]) continue;
            int target = -(nums[i] + nums[j]);
            if(umap.count(target) && umap[target] > j) res.push_back({nums[i], nums[j], target});
        }
    }
    return res;
}
vector<vector<int>> threeSum(vector<int>& nums) { // 三数之和 双指针
    sort(nums.begin(), nums.end());
    int n = nums.size();
    vector<vector<int>> res;
    for (int i = 0; i < n - 2; i++)
    {
        if(nums[i] > 0) break;
        if(i > 0 && nums[i] == nums[i - 1]) continue;
        int left = i + 1, right = n - 1;
        while (left < right)
        {
            //if(nums[left] + nums[left + 1] > -nums[i]) break;
            //if(nums[right] + nums[right - 1] < -nums[i]) break;
            int sum = nums[left] + nums[right];
            if(sum == -nums[i]) {
                res.push_back({nums[i], nums[left], nums[right]});
                while (left + 1 < right && nums[left + 1] == nums[left]) ++left;
                ++left;
                while (right - 1 > left && nums[right - 1] == nums[right]) --right;
                --right; 
            }
            else if(sum < -nums[i]) ++left;
            else --right;
        }
    }
    return res;
}
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    vector<vector<int>> res;
    for (int i = 0; i < n - 3; i++)
    {
        if(nums[i] >= 0 && nums[i] > target) break;
        if(i > 0 && nums[i] == nums[i - 1]) continue;
        for (int j = i + 1; j < n - 2; j++)
        {
            long long sum1 = (long long)nums[i] + nums[j];
            if(sum1 >= 0 && sum1 > target) break;
            if(j > i + 1 && nums[j] == nums[j - 1]) continue;
            int left = j + 1, right = n - 1;
            while (left < right)
            {
                long long sum2 = (long long)nums[left] + nums[right];
                if(sum2 == target - sum1) {
                    res.push_back({nums[i], nums[j], nums[left], nums[right]});
                    while (left + 1 < right && nums[left + 1] == nums[left]) ++left;
                    ++left;
                    while (right - 1 > left && nums[right - 1] == nums[right]) --right;
                    --right; 
                }
                else if(sum2 < target - sum1) ++left;
                else --right;
            }
        }
    }
    return res;
}



int main() {
    string s = "acdcaeccde";
    string p = "c";
    findAnagrams(s, p);

    return 0;
}