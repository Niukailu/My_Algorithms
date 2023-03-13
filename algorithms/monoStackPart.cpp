#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>

using namespace std;

//739. 每日温度
vector<int> dailyTemperatures(vector<int>& temperatures) {
    vector<int> res(temperatures.size(), 0);
    stack<int> stk;
    for(int i = 0; i < temperatures.size(); i++) {
        while(!stk.empty() && temperatures[i] > temperatures[stk.top()]) {
            res[stk.top()] = i - stk.top();
            stk.pop(); 
        }
        stk.push(i);
    }
    return res;
}

//42. 接雨水
int trap1(vector<int>& height) { //动规
    int len = height.size(); 
    vector<int> lefts(len, 0), rights(len, 0);
    int maxleft = 0;
    for (int i = 1; i < len; i++)
    {
        maxleft = max(maxleft, height[i - 1]);
        lefts[i] = maxleft;
    }
    int maxright = 0;
    for (int i = len - 2; i >= 0; i--)
    {
        maxright = max(maxright, height[i + 1]);
        rights[i] = maxright;
    }
    int res = 0;
    for (int i = 0; i < len; i++)
    {
        int tmp = min(lefts[i], rights[i]) - height[i];
        if(tmp > 0) res += tmp;
    }
    return res;
}
int trap(vector<int>& height) { //单调栈
    stack<int> stk;
    int res = 0;
    for (int i = 0; i < height.size(); i++)
    {
        while (!stk.empty() && height[i] > height[stk.top()]) //找凹槽
        {
            int mid = height[stk.top()];
            stk.pop();
            if(!stk.empty()) {
                int hei = min(height[i], height[stk.top()]) - mid;
                int wei = i - stk.top() - 1;
                res += hei * wei;
            }
        }
        stk.push(i);
    }
    return res;
}

vector<int> nextGreaterElements(vector<int>& nums) {
    int len = nums.size();
    vector<int> res(len, -1);
    stack<int> stk;
    for(int i = 0; i < 2 * len; i++) {
        while(!stk.empty() && nums[i % len] > nums[stk.top()]) {
            res[stk.top()] = nums[i % len];
            stk.pop();
        }
        stk.push(i % len);
    }
    return res;
}

int largestRectangleArea(vector<int>& heights) { //84.柱状图中最大的矩形
    heights.insert(heights.begin(), 0);
    heights.push_back(0);
    stack<int> stk;
    stk.push(0);
    int res = 0;
    for (int i = 1; i < heights.size(); i++)
    {
        while (heights[i] < heights[stk.top()])
        {
            int hei = heights[stk.top()];
            stk.pop();
            res = max(res, hei * (i - stk.top() - 1));
        }
        stk.push(i);
    }
    return res;
}