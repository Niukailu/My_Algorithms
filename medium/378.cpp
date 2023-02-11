#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

//二分法（着实想不到。。）
int leqnum(vector<vector<int>>& matrix, int& n, int mid) {
    int count = 0;
    int i = n - 1, j = 0;
    while (i >= 0 && j < n)
    {
        if(matrix[i][j] <= mid) {
            count += (i + 1);
            ++j;
        }
        else --i;
    }
    return count;
}
int kthSmallest(vector<vector<int>>& matrix, int k) {
    int n = matrix.size();
    int left = matrix[0][0];
    int right = matrix[n - 1][n - 1];
    int mid = 0;
    while (left < right)
    {
        mid = left + (right - left) >> 1;
        if(leqnum(matrix, n, mid) < k) left = mid + 1;
        else right = mid;
    }
    return left;
}
//解法二，归并排序
//先复习一下第23.合并K个升序链表
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
struct comp
{
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};
ListNode* mergeKLists(vector<ListNode*>& lists) {
    priority_queue<ListNode*, vector<ListNode*>, comp> small_heap;
    for(auto& it : lists) {
        if(it) small_heap.push(it);
    }
    ListNode* dummyhead = new ListNode(0);
    ListNode* cur = dummyhead;
    while (!small_heap.empty())
    {
        ListNode* node = small_heap.top();
        small_heap.pop();
        if(node->next) small_heap.push(node->next);
        cur->next = node;
        cur = cur->next;
    }
    return dummyhead->next;
}
//针对本题的归并排序
struct point
{
    int val, i, j;
    point(int val, int i, int j) : val(val), i(i), j(j) {}
    bool operator > (const point& a) const {
        return this->val > a.val;
    }
};
int kthSmallest(vector<vector<int>>& matrix, int k) {
    int n = matrix.size();
    priority_queue<point, vector<point>, greater<point>> small_heap;
    for (int i = 0; i < n; i++)
    {
        small_heap.push(point(matrix[i][0], i, 0));
    }
    int res = 0;
    while (k--)
    {
        point cur = small_heap.top();
        res = cur.val;
        small_heap.pop();
        if(cur.j < n) small_heap.push(point(matrix[cur.i][cur.j + 1], cur.i, cur.j + 1));
    }
    return res;
}

int main() {
    

    return 0;
}