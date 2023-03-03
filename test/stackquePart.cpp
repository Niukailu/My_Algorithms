#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <list>
#include <unordered_map>

using namespace std;

class MyQueue {
private:
    stack<int> in_stk, out_stk;
public:
    MyQueue() {

    }
    
    void push(int x) {
        in_stk.push(x);
    }
    
    int pop() {
        if(out_stk.empty()) {
            while (!in_stk.empty())
            {            
                out_stk.push(in_stk.top());
                in_stk.pop();
            }
        }
        int res = out_stk.top();
        out_stk.pop();
        return res;
    }
    
    int peek() {
        int res = this->pop();
        out_stk.push(res);
        return res;
    }
    
    bool empty() {
        return in_stk.empty() && out_stk.empty();
    }
};
class MyStack {
private:
    queue<int> que;
public:
    MyStack() {

    }
    
    void push(int x) {
        que.push(x);
    }
    
    int pop() {
        int len = que.size();
        while (--len)
        {
            que.push(que.front());
            que.pop();
        }
        int num = que.front();
        que.pop();
        return num;
    }
    
    int top() {
        return que.back();
    }
    
    bool empty() {
        return que.empty();
    }
};
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> dq;
    vector<int> res;
    for (int i = 0; i < nums.size(); i++)
    {
        while (!dq.empty() && dq.back() < nums[i])
        {
            dq.pop_back();
        }
        dq.push_back(nums[i]);
        if(i >= k) {
            if(dq.front() == nums[i - k]) dq.pop_front();
        }
        if(i >= k - 1) res.push_back(dq.front());
    }
    return res;
}

struct cmp
{
    bool operator () (const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second;
    }
};
vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> umap;
    for(int& num : nums) {
        ++umap[num];
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> que;
    for(auto& it : umap) {
        que.emplace(it);
        if(que.size() > k) que.pop();
    }
    vector<int> res;
    while (!que.empty())
    {
        res.push_back(que.top().first);
        que.pop();
    }
    return res;
}



struct point
{
    int x, y;
    point(int x, int y) : x(x), y(y) {}
    bool operator < (const point& a) const {
        if(x == a.x) return y > a.y;
        return x > a.x;
    }
};
// struct cmp
// {
//     bool operator () (const point& a, const point& b) {
//         if(a.x == b.x) return a.y > b.y;
//         return a.x > b.x;
//     }
// };

int main() {
    priority_queue<point, vector<point>, less<point>> que;
    for (int i = 0; i < 5; i++)
    {
        que.push(point(rand(), rand()));
    }
    while (!que.empty())
    {
        cout << que.top().x << " " << que.top().y << endl;
        que.pop();
    }
    
    
    return 0;
}