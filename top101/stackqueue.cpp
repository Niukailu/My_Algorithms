#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    stack<int> nums, minnums;
public:
    void push(int value) {
        nums.push(value);
        if(minnums.empty() || value <= minnums.top()) minnums.push(value);
    }
    void pop() {
        if(minnums.top() == nums.top()) minnums.pop();
        nums.pop();
    }
    int top() {
        return nums.top();
    }
    int min() {
        return minnums.top();
    }
};

vector<int> maxInWindows(const vector<int>& num, unsigned int size) {
    if(size > num.size() || size == 0) return {};
    deque<int> que;
    vector<int> res;
    for (int i = 0; i < num.size(); i++)
    {
        while (!que.empty() && que.back() < num[i]) que.pop_back();
        que.push_back(num[i]);
        if(i >= size && num[i - size] == que.front()) que.pop_front();
        if(i >= size - 1) res.push_back(que.front());
    }
    return res;
}

vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
    priority_queue<int> maxque;
    for(int& it : input) {
        maxque.push(it);
        if(maxque.size() > k) maxque.pop();
    }
    vector<int> res;
    while (!maxque.empty())
    {
        res.push_back(maxque.top());
        maxque.pop();
    }
    return res; 
}

int _solve(string& s, int& start) { //好麻烦，不会写。。
    stack<int> nums;
    stack<char> opts;
    while (start < s.length())
    {
        if(s[start] == ')') {
            ++start;
            break;
        }
        else if(s[start] == '(') {
            ++start;
            nums.push(_solve(s, start));
            ++start;
        }
        else if(s[start] >= '0' && s[start] <= '9') {
            int num = 0;
            while (start < s.length() && s[start] >= '0' && s[start] <= '9') {
                num = num * 10 + (s[start++] - '0');
            }
            if(!opts.empty() && opts.top() == '*') {
                num = nums.top() * num;
                nums.pop();
                opts.pop();
            }
            nums.push(num);
        }
        else opts.push(s[start++]);
    }
    while (!opts.empty())
    {
        int num2 = nums.top();
        nums.pop();
        int num1 = nums.top();
        nums.pop();
        if(opts.top() == '+') nums.push(num1 + num2);
        else nums.push(num1 - num2);
        opts.pop();
    }
    return nums.top();
}
int solve(string s) {
    int start = 0;
    return _solve(s, start);
}
