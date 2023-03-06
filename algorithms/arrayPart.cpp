#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

//数组部分
//二分
int search(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    int mid = 0;
    while (left <= right)
    {
        mid = left + ((right - left) >> 1);
        if(target == nums[mid]) return mid;
        else if(target < nums[mid]) right = mid - 1;
        else left = mid + 1;
    }
    return -1;
}
// 34. 在排序数组中查找元素的第一个和最后一个位置
int getleft(vector<int>& nums, int& target) {
    int left = 0, right = nums.size() - 1, mid = 0;
    while (left <= right)
    {
        mid = left + ((right - left) >> 1);
        if(target > nums[mid]) left = mid + 1;
        else right = mid - 1;
    }
    return left < nums.size() && nums[left] == target ? left : -1;
}
int getright(vector<int>& nums, int& target) {
    int left = 0, right = nums.size() - 1, mid = 0;
    while (left <= right)
    {
        mid = left + ((right - left) >> 1);
        if(target >= nums[mid]) left = mid + 1;
        else right = mid - 1;
    }
    return left - 1 >= 0 && nums[left - 1] == target ? left - 1 : -1;
}
vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> res = {-1, -1};
    if(nums.size() == 0 || target < nums[0] || target > nums[nums.size() - 1]) return res;
    res[0] = getleft(nums, target);
    res[1] = getright(nums, target);
    return res;
}
// 69. x 的平方根 
int mySqrt(int x) {
    if(x < 2) return x;
    int left = 0, right = x;
    while (left <= right)
    {
        int mid = left + ((right - left) >> 1);
        if(x / mid == mid) return mid;
        else if(x / mid < mid) right = mid - 1;
        else left = mid + 1;
    }
    return right;
}

//27. 移除元素
int removeElement(vector<int>& nums, int val) { //改变顺序
    int left = 0, right = nums.size() - 1;
    while (left <= right)
    {
        if(nums[left] == val) {
            swap(nums[left], nums[right]);
            --right;
        }
        else ++left;
    }
    return left;
}
int removeElement2(vector<int>& nums, int val) { //不改变顺序
    int j = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if(nums[i] != val) nums[j++] = nums[i];
    }
    return j;
}
int removeDuplicates(vector<int>& nums) { //26. 删除有序数组中的重复项
    int j = 1;
    for (int i = 1; i < nums.size(); i++)
    {
        if(nums[i] != nums[j - 1]) nums[j++] = nums[i];
    }
    return j;
}
int removeDuplicates2(vector<int>& nums) { //使得出现次数超过两次的元素只出现两次 
    if(nums.size() <= 2) return nums.size();
    int j = 2;
    for (int i = 2; i < nums.size(); i++)
    {
        if(nums[i] != nums[j - 2]) nums[j++] = nums[i];
    }
    return j;
}
void moveZeroes(vector<int>& nums) { //283. 移动零,尽量减少完成的操作次数
    int j = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if(nums[i] != 0) {
            if(j != i) {
                nums[j] = nums[i];
                nums[i] = 0;
            }
            ++j;
        }
    }
}
//???一直在原数组上搞。。。妈的气死我了
vector<int> sortedSquares(vector<int>& nums) { //977. 有序数组的平方
    vector<int> res(nums.size(), 0);
    int k = nums.size() - 1;
    for (int i = 0, j = nums.size() - 1; i <= j;)
    {
        int left = nums[i] * nums[i];
        int right = nums[j] * nums[j];
        if(left > right) {
            res[k--] = left;
            ++i;
        }
        else {
            res[k--] = right;
            --j;
        }
    }
    return res;
}
int minSubArrayLen(int target, vector<int>& nums) {
    int sum = target;
    int res = INT32_MAX;
    for (int i = 0, j = 0; j < nums.size(); ) {
        sum -= nums[j++];
        while (sum <= 0)
        {
            res = min(res, j - i);
            if(res == 1) return 1;
            sum += nums[i++];
        }
    }
    return res == INT32_MAX ? 0 : res;
}
int totalFruit(vector<int>& fruits) {
    if(fruits.size() < 3) return fruits.size();
    unordered_map<int, int> kinds;
    int res = 0;
    for (int left = 0, right = 0; right < fruits.size(); right++)
    {
        kinds[fruits[right]]++;
        while (kinds.size() > 2)
        {
            kinds[fruits[left]]--;
            if(kinds[fruits[left]] == 0) kinds.erase(fruits[left]);
            left++;
        }
        res = max(res, right - left + 1);
    }
    return res;
}
// 76. 最小覆盖子串(滑动窗口)
string minWindow(string s, string t) {
    if(s.length() < t.length()) return "";
    unordered_map<char, int> kinds;
    unordered_set<char> uset;
    for(char& c : t) {
        kinds[c]++;
        uset.emplace(c);
    }
    int len = INT32_MAX, left = 0;
    for (int i = 0, j = 0; j < s.length(); j++)
    {
        if(kinds.count(s[j])) {
            kinds[s[j]]--;
            if(kinds[s[j]] == 0) uset.erase(s[j]);
        }
        while (uset.size() == 0)
        {
            if(j - i + 1 < len) {
                len = j - i + 1;
                left = i;
            }
            if(kinds.count(s[i])) {
                kinds[s[i]]++;
                if(kinds[s[i]] > 0) uset.emplace(s[i]);
            }
            i++;
        }
    }
    return len == INT32_MAX ? "" : s.substr(left, len);
}
//59. 螺旋矩阵 II
vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> res(n, vector<int>(n, 0));
    int i = 0, j = -1;
    int k = 1;
    while (k <= n*n)
    {
        while (j + 1 < n && res[i][j + 1] == 0)
        {
            res[i][++j] = k++;
        }
        while (i + 1 < n && res[i + 1][j] == 0)
        {
            res[++i][j] = k++;
        }
        while (j - 1 >= 0 && res[i][j - 1] == 0)
        {
            res[i][--j] = k++;
        }
        while (i - 1 >= 0 && res[i - 1][j] == 0)
        {
            res[--i][j] = k++;
        }
    }
    return res;
}
vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    vector<int> res;
    int i = 0, j = -1;
    int k = m * n;
    while (k > 0)
    {
        while (j + 1 < n && matrix[i][j + 1] != 1000)
        {
            res.push_back(matrix[i][j + 1]);
            matrix[i][++j] = 1000;
            k--;
        }
        while (i + 1 < m && matrix[i + 1][j] != 1000)
        {
            res.push_back(matrix[i + 1][j]);
            matrix[++i][j] = 1000;
            k--;
        }
        while (j - 1 >= 0 && matrix[i][j - 1] != 1000)
        {
            res.push_back(matrix[i][j - 1]);
            matrix[i][--j] = 1000;
            k--;
        }
        while (i - 1 >= 0 && matrix[i - 1][j] != 1000)
        {
            res.push_back(matrix[i - 1][j]);
            matrix[--i][j] = 1000;
            k--;
        }
    }
    return res;
}