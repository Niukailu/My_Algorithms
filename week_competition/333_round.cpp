#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <map>

using namespace std;

vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
    map<int, int> mp;
    for(auto& it : nums1) {
        mp[it[0]] += it[1];
    } 
    for(auto& it : nums2) {
        mp[it[0]] += it[1];
    } 
    vector<vector<int>> res;
    for(auto& it : mp) {
        res.push_back({it.first, it.second});
    } 
    return res;   
}

int minOperations(int n) {
    int opt = 0, num = 0;
    while (n)
    {
        if(n & 1) num++;
        else {
            if(num) opt++;
            if(num == 1) num = 0;
            else if(num >= 2) num = 1;
        }
        n >>= 1;
    }
    if(num == 1) opt++;
    else if(num >= 2) opt += 2;
    return opt;    
}

string findTheString2(vector<vector<int>>& lcp) {//啊啊啊没写出来。。
    int n = lcp.size();
    string res(n, 'a');
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(i == j) {
                if(lcp[i][j] != n - i) return "";
            }
            else if(i < j) {
                if(lcp[i][j] != lcp[j][i] || lcp[j][i] > n - j) return "";
                int k = lcp[j][i];
                for (int l = 0; l < k; l++)
                {
                    if(res[j + l] != res[i + l]) {
                        if(res[j + l] > res[i + l]) return "";
                        res[j + l] = res[i + l];
                    }
                }
                if(j + k < n && res[j + k] == res[i + k]) {
                    if(res[i + k] + 1 > 'z') return "";
                    res[j + k] = res[i + k] + 1;
                }
            }
        }
    }
    return res;
}
string findTheString(vector<vector<int>>& lcp) {
    int n = lcp.size();
    string s(n, '0');
    char c = 'a';
    for (int i = 0; i < n; i++) //假设lcp正确，构造最优s
    {
        if(lcp[i][i] != n - i) return "";
        if(s[i] == '0') {
            if(c > 'z') return "";
            s[i] = c;
            for (int j = i + 1; j < n; j++)
            {
                if(lcp[i][j] != lcp[j][i] || lcp[i][j] > n - j) return "";
                if(lcp[i][j] > 0) s[j] = c;
            } 
            c += 1;
        }
    }
    //根据s计算lcp判断是否正确(动规)
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = n - 1; j > i; j--)
        {
            if(s[i] == s[j]) {
                int num = j == n - 1 ? 1 : lcp[i + 1][j + 1] + 1;
                if(num != lcp[i][j]) return "";
            }
        }
    }
    return s;
}

//98双周赛
int minMaxDifference(int num) {
    vector<int> nums;
    while (num)
    {
        nums.push_back(num % 10);
        num /= 10;
    }
    int maxi = 0;
    int tmp1 = -1;
    for (int i = nums.size() - 1; i >= 0; i--)
    {
        if(tmp1 == -1 && nums[i] != 9) tmp1 = nums[i];
        if(nums[i] == tmp1) maxi = maxi * 10 + 9;
        else maxi = maxi * 10 + nums[i];
    }
    int mini = 0;
    int tmp2 = -1;
    for (int i = nums.size() - 1; i >= 0; i--)
    {
        if(tmp2 == -1) tmp2 = nums[i];
        if(nums[i] == tmp2) mini = mini * 10 + 0;
        else mini = mini * 10 + nums[i];
    }
    return maxi - mini;
}
int minimizeSum(vector<int>& nums) {
    if(nums.size() == 3) return 0;
    
}


int main() {
    string res(5, 'a');
    cout << res << endl;

    return 0;
}