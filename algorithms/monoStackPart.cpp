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

