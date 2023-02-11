#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <random>

using namespace std;


class RandomizedSet {
private:
    vector<int> nums;
    unordered_map<int, int> umap;
    int len = 0;
public:
    RandomizedSet() {

    }
    
    bool insert(int val) {
        if(umap.count(val)) return false;
        nums.push_back(val);
        umap[val] = len;
        ++len;
        return true;
    }
    
    bool remove(int val) {
        if(!umap.count(val)) return false;
        umap[nums[len - 1]] = umap[val];
        swap(nums[umap[val]], nums[len - 1]);
        nums.pop_back();
        umap.erase(val);
        --len;
        return true;
    }
    
    int getRandom() {
        return nums[rand() % len];
    }
};

//384. 打乱数组
//竟然自己想到了和题解一样的打乱方法！
class Solution {
private:
    vector<int> nums;
public:
    Solution(vector<int>& nums) {
        this->nums = nums;
    }
    
    vector<int> reset() {
        return nums;
    }
    
    vector<int> shuffle() {
        vector<int> shuffle_nums(nums);
        int len = nums.size();
        for (int i = 0; i < len; i++)
        {
            int idx = i + rand() % (len - i);
            swap(shuffle_nums[i], shuffle_nums[idx]);
        }
        return shuffle_nums;
    }
};
