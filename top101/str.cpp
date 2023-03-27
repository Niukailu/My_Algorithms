#include <bits/stdc++.h>

using namespace std;


void reverse_s(string& s, int left, int right) {
    for(int i = left, j = right; i < j; i++, j--) {
        swap(s[i], s[j]);
    }
}
string trans(string s, int n) {
    int i = 0;
    while (i < n)
    {
        if(s[i] != ' ') {
            int j = i;
            while (j < n && s[j] != ' ') j++;
            reverse_s(s, i, j - 1);
            i = j;
        }
        else i++;
    }
    reverse_s(s, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        if(s[i] != ' ') {
            if(s[i] >= 'a' && s[i] <= 'z') s[i] -= 32;
            else s[i] += 32;
        }
    }
    return s;
}

string longestCommonPrefix(vector<string>& strs) {
    if(strs.size() == 0) return "";
    string pre = strs[0];
    for (int i = 1; i < strs.size(); i++)
    {
        int len = min(pre.length(), strs[i].length());
        int j = 0;
        for (; j < len; j++)
        {
            if(pre[j] != strs[i][j]) break;
        }
        pre = pre.substr(0, j);
        if(pre == "") return "";
    }
    return pre;
}

string solve(string IP) {
    vector<string> ss;
    int i = 0;
    int kind = 0;
    while (i < IP.length())
    {
        if(IP[i] != '.' || IP[i] != ':') {
            string s = "";
            while (i < IP.length() && (IP[i] != '.' || IP[i] != ':'))
            {
                s += IP[i++];
            }
            ss.push_back(s);
            
        }
        else {
            if(i == 0 || i == IP.length() - 1 || IP[i - 1] == '.' || IP[i - 1] == ':') return "Neither";
            if(IP[i] == ':') {
                if(kind != 1) kind = 2;
                else return "Neither";
            }
            else {
                if(kind != 2) kind = 1;
                else return "Neither";
            } 
            i++;
        }
    }
    if(kind == 1 && ss.size() == 4) {
        for (int i = 0; i < 4; i++)
        {
            int num = 0;
            for (int j = 0; j < ss[i].length(); j++)
            {
                if(j > 0 && ss[i][0] == '0') return "Neither";
                if(ss[i][j] < '0' || ss[i][j] > '9') return "Neither";
                num = num * 10 + (ss[i][j] - '0');
            }
            if(num > 255) return "Neither";
        }
        return "IPv4";
    }
    else if(kind == 2 && ss.size() == 8) {
        for (int i = 0; i < 8; i++)
        {
            if(ss[i].length() > 4) return "Neither";
            for (int j = 0; j < ss[i].length(); j++)
            {
                if(ss[i][j] > 'f' && ss[i][j] <= 'z') return "Neither";
                if(ss[i][j] > 'F' && ss[i][j] <= 'Z') return "Neither";
            }
        }
        return "IPv6";
    }
    else return "Neither";
}

string solve(string s, string t) {
    if(s == "") return t;
    if(t == "") return s;
    int i = s.length() - 1, j = t.length() - 1;
    int carry = 0;
    string res = "";
    while (i >= 0 || j >= 0)
    {
        int a = 0, b = 0;
        if(i >= 0) a = s[i--] - '0';
        if(j >= 0) b = t[j--] - '0';
        int num = a + b + carry;
        carry = num / 10;
        res += ('0' + num % 10);
    }
    if(carry) res += ('0' + carry); 
    reverse(res.begin(), res.end());
    return res;
}

void merge(int A[], int m, int B[], int n) {
    for(int i = 0; i < m; i++) {
        A[m + n - 1 - i] = A[m - 1 - i];
    }
    int i = n, j = 0;
    int k = 0;
    while (i < m + n && j < n)
    {
        if(A[i] < B[j]) {
            A[k++] = A[i++];
        }
        else A[k++] = B[j++];
    }
    if(i >= m + n) {
        while(j < n) A[k++] = B[j++];
    }   
}

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

vector<Interval> merge(vector<Interval> &intervals) {
    if(intervals.size() == 0) return {};
    sort(intervals.begin(), intervals.end(), [](auto& a, auto& b){
        return a.start < b.start;
    });
    vector<Interval> res;
    int left = intervals[0].start, right = intervals[0].end;
    for(auto& it : intervals) {
        if(it.start > right) {
            res.push_back(Interval(left, right));
            left = it.start, right = it.end;
        }
        else {
            right = max(right, it.end);
        }
    }
    res.push_back(Interval(left, right));
    return res;
}

int maxLength(vector<int>& arr) {
    unordered_set<int> uset;
    int i = 0, j = 0;
    int res = 0;
    while (j < arr.size())
    {
        while (uset.count(arr[j]))
        {
            uset.erase(arr[i++]);
        }
        uset.emplace(arr[j]);
        res = max(res, j - i + 1);
        j++;
    }
    return res;   
}

int maxArea(vector<int>& height) {
    if(height.size() < 2) return 0;
    int left = 0, right = height.size() - 1;
    int res = 0;
    while (left < right)
    {
        res = max(res, (right - left) * min(height[left], height[right]));
        if(height[left] < height[right]) left++;
        else right--;
    }
    return res;
}

long long maxWater(vector<int>& arr) {
    stack<int> stk;
    long long res = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        while (!stk.empty() && arr[i] > arr[stk.top()])
        {
            int mid = arr[stk.top()];
            stk.pop();
            if(!stk.empty()) {
                int left = stk.top();
                int hei = min(arr[left], arr[i]);
                res += (long long)(i - left - 1) * (hei - mid);
            }
        }
        stk.push(i);
    }
    return res;
}

int candy(vector<int>& arr) {
    vector<int> nums(arr.size(), 1);
    for(int i = 1; i < arr.size(); i++) {
        if(arr[i] > arr[i - 1]) nums[i] = nums[i - 1] + 1;
    }
    for(int i = arr.size() - 2; i >= 0; i--) {
        if(arr[i] > arr[i + 1]) nums[i] = max(nums[i], nums[i + 1] + 1);
    }
    int res = 0;
    for(int& it : nums) {
        res += it;
    }
    return res;
}

int minmumNumberOfHost(int n, vector<vector<int> >& startEnd) {
    vector<pair<int, int>> times;
    for(auto& it : startEnd) {
        times.push_back(make_pair(it[0], 1));
        times.push_back(make_pair(it[1], 0));
    }
    sort(times.begin(), times.end());
    int num = 0, res = 0;
    for(auto& it : times) {
        if(it.second) num++;
        else num--;
        res = max(res, num);
    }
    return res;
}

void reverse_a(vector<int>& a, int begin, int end) {
    for(int i = begin, j = end; i < j; i++, j--) {
        swap(a[i], a[j]);
    }
}
vector<int> solve(int n, int m, vector<int>& a) {
    reverse_a(a, 0, n - 1);
    m %= n;
    reverse_a(a, 0, m - 1);
    reverse_a(a, m, n - 1);
    return a;
}

vector<int> spiralOrder(vector<vector<int> > &matrix) {
    if(matrix.size() == 0) return {};
    int m = matrix.size(), n = matrix[0].size();  
    vector<int> res;
    int i = 0, j = -1;
    while (true)
    {
        while (j + 1 < n && matrix[i][j + 1] != 200)
        {
            res.push_back(matrix[i][j + 1]);
            j++;
            matrix[i][j] = 200;
        }
        while (i + 1 < m && matrix[i + 1][j] != 200)
        {
            res.push_back(matrix[i + 1][j]);
            i++;
            matrix[i][j] = 200;
        }
        while (j - 1 >= 0 && matrix[i][j - 1] != 200)
        {
            res.push_back(matrix[i][j - 1]);
            j--;
            matrix[i][j] = 200;
        }
        while (i - 1 >= 0 && matrix[i - 1][j] != 200)
        {
            res.push_back(matrix[i - 1][j]);
            i--;
            matrix[i][j] = 200;
        }
        if(res.size() == m * n) break;
    }
    return res;
}

vector<vector<int> > rotateMatrix(vector<vector<int> > mat, int n) {
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(i + j < n){
                swap(mat[i][j], mat[n - j - 1][n - i - 1]);
            }
        }
    }
    for (int i = 0; i < n /2; i++)
    {
        for (int j = 0; j < n; j++)
        {
            swap(mat[i][j], mat[n - i - 1][j]);
        }
    }
    return mat;
}


class Solution {
private:
    struct ListNode{
        int key;
        int val;
        ListNode* pre;
        ListNode* next;
        ListNode(int x, int y) : key(x), val(y), pre(nullptr), next(nullptr) {}
    };

    unordered_map<int, ListNode*> umap;
    ListNode* dummyhead = new ListNode(0, 0);
    ListNode* end = dummyhead;
    int size = 0;

    void insert_node(int key, int value) {
        ListNode* next = dummyhead->next;
        ListNode* cur = new ListNode(key, value);
        dummyhead->next = cur;
        cur->next = next;
        if(next != nullptr) next->pre = cur;
        cur->pre = dummyhead;
        if(end == dummyhead) end = cur;
        umap[key] = cur;
        size--;
    }

    void delete_node(ListNode*& node) {
        node->pre->next = node->next;
        if(node != end) node->next->pre = node->pre;
        else end = node->pre;
        umap.erase(node->key);
        delete node;
        size++;
    }

public:
    Solution(int capacity){
        this->size = capacity;
    }
    
    int get(int key) {
        if(umap.count(key)) {
            int value = umap[key]->val;
            delete_node(umap[key]);
            insert_node(key, value);
            return value;
        }
        else return -1;
    }
    
    void set(int key, int value){
        if(umap.count(key)) delete_node(umap[key]);
        insert_node(key, value);
        if(size < 0) delete_node(end);
    }
};



int main() {




    return 0;
}



