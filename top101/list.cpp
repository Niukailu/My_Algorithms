#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* reverseBetween(ListNode* head, int m, int n) {
    int steps = n - m + 1;
    ListNode* dummyhead = new ListNode(0);
    dummyhead->next = head;
    ListNode* start = dummyhead;
    while(--m) start = start->next;
    ListNode *pre = start, *cur = start->next;
    while (steps--)
    { 
        ListNode* next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    start->next->next = cur;
    start->next = pre;    
    return dummyhead->next;
}

ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode* dummyhead = new ListNode(0);
    dummyhead->next = head;
    ListNode *start = dummyhead, *end = dummyhead;
    int num = 0;
    while (end->next != nullptr)
    {
        end = end->next;
        ++num;
        if(num % k == 0) {
            ListNode *pre = start, *cur = start->next;
            int steps = k;
            while (steps--)
            { 
                ListNode* next = cur->next;
                cur->next = pre;
                pre = cur;
                cur = next;
            }
            start->next->next = cur;
            ListNode *tmp = start->next;
            start->next = pre; 
            start = tmp, end = tmp;
        }
    }
    return dummyhead->next;
}

struct cmp
{
    bool operator () (ListNode*& a, ListNode*& b) {
        return a->val > b->val;
    }
};

ListNode *mergeKLists(vector<ListNode *> &lists) {
    priority_queue<ListNode*, vector<ListNode*>, cmp> que;
    for(auto& it : lists) {
        if(it != nullptr) que.push(it);
    } 
    ListNode* dummyhead = new ListNode(0);
    ListNode* pre = dummyhead;
    while (!que.empty())
    {
        ListNode* cur = que.top();
        que.pop();
        if(cur->next != nullptr) que.push(cur->next);
        pre->next = cur;
        cur->next = nullptr;
        pre = cur; 
    }
    return dummyhead->next;  
}

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* dummyhead = new ListNode(0);
    dummyhead->next = head;
    ListNode *pre = dummyhead, *cur = dummyhead;
    while(n--) cur = cur->next;
    while (cur && cur->next != nullptr)
    {
        cur = cur->next;
        pre = pre->next;
    }
    ListNode *tmp = pre->next;
    pre->next = pre->next->next;
    delete tmp;
    return dummyhead->next;
}

ListNode* addInList(ListNode* head1, ListNode* head2) {
    stack<ListNode*> stk1, stk2;
    ListNode *cur = head1;
    while(cur != nullptr) {
        stk1.push(cur);
        cur = cur->next;
    }
    cur = head2;
    while(cur != nullptr) {
        stk2.push(cur);
        cur = cur->next;
    }
    cur = nullptr;
    ListNode *end = nullptr;
    int carry = 0;
    while (!stk1.empty() || !stk2.empty())
    {
        ListNode *left = nullptr, *right = nullptr;
        if(!stk1.empty()) left = stk1.top(), stk1.pop();
        if(!stk2.empty()) right = stk2.top(), stk2.pop();
        cur = new ListNode(carry);
        if(left != nullptr) cur->val += left->val;
        if(right != nullptr) cur->val += right->val;
        carry = cur->val / 10;
        cur->val = cur->val % 10;
        cur->next = end;
        end = cur;
    }
    if(carry) {
        cur = new ListNode(carry);
        cur->next = end;
        end = cur;
    }
    return end;
}

ListNode* merge(ListNode *left, ListNode *right) {
    ListNode *dummyhead = new ListNode(0);
    ListNode *pre = dummyhead;
    while (left != nullptr && right != nullptr)
    {
        if(left->val < right->val) {
            pre->next = left;
            left = left->next;
        }
        else {
            pre->next = right;
            right = right->next;
        }
        pre = pre->next;
    }
    pre->next = left == nullptr ? right : left;
    return dummyhead->next;
}
ListNode* merge_sort(ListNode* begin) {
    if(begin == nullptr || begin->next == nullptr) return begin;
    ListNode *slow = begin, *quick = begin->next;
    while (quick != nullptr && quick->next != nullptr)
    {
        quick = quick->next->next;
        slow = slow->next;
    }
    ListNode* rhead = slow->next;
    slow->next = nullptr;
    ListNode *left = merge_sort(begin);
    ListNode *right = merge_sort(rhead);
    return merge(left, right);
}
ListNode* sortInList(ListNode* head) {
    return merge_sort(head);
}

ListNode* oddEvenList(ListNode* head) {
    if(head == nullptr || head->next == nullptr) return head;
    ListNode *odd = head, *even = head->next;
    ListNode *cur1 = odd, *cur2 = even;
    while (cur2 != nullptr && cur2->next != nullptr)
    {
        cur1->next = cur1->next->next;
        cur1 = cur1->next;
        cur2->next = cur2->next->next;
        cur2 = cur2->next;
    }
    cur1->next = even;
    return odd;
}

ListNode* deleteDuplicates(ListNode* head) {
    if(head == nullptr || head->next == nullptr) return head;
    ListNode* dummyhead = new ListNode(0);
    dummyhead->next = head;
    ListNode *pre = dummyhead, *cur = head;
    int value = cur->val;
    while (cur != nullptr)
    {
        if(cur->next != nullptr && cur->next->val == value) {
            while (cur != nullptr && cur->val == value)
            {
                ListNode *tmp = cur;
                cur = cur->next;
                delete tmp;
                pre->next = cur;
            }
        }
        else {
            pre = cur;
            cur = cur->next;
        }
        if(cur != nullptr) value = cur->val;
    }
    return dummyhead->next;
}


ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
    ListNode* dummyhead = new ListNode(0);
    ListNode* pre = dummyhead;
    while (pHead1 != nullptr && pHead2 != nullptr)
    {
        if(pHead1->val < pHead2->val) {
            pre->next = pHead1;
            pre = pHead1;
            pHead1 = pHead1->next;
        }
        else {
            pre->next = pHead2;
            pre = pHead2;
            pHead2 = pHead2->next;
        }
    }
    if(pHead1 != nullptr) pre->next = pHead1;
    else pre->next = pHead2;
    return dummyhead->next;  
}

void reorderList(ListNode* head) {
    if(head == nullptr || head->next == nullptr) return;
    ListNode *slow = head, *quick = head;
    while (quick != nullptr && quick->next != nullptr)
    {
        quick = quick->next->next;
        slow = slow->next;
    }
    ListNode* cur = slow->next;
    slow->next = nullptr;
    ListNode* pre = nullptr;
    while (cur != nullptr)
    {
        ListNode* next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    ListNode *left = head, *right = pre;
    while (left != nullptr && right != nullptr)
    {
        ListNode* next = left->next;
        left->next = right;
        ListNode* next2 = right->next;
        right->next = next;
        left = next;
        right = next2;
    }
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* dummyhead = new ListNode(0);
    ListNode* pre = dummyhead;
    int carry = 0;
    while (l1 != nullptr || l2 != nullptr)
    {
        int a = 0, b = 0;
        if(l1 != nullptr) {
            a = l1->val;
            l1 = l1->next;
        }
        if(l2 != nullptr) {
            b = l2->val;
            l2 = l2->next;
        }
        int tmp = carry + a + b;
        ListNode* cur = new ListNode(tmp % 10);
        pre->next = cur;
        pre = pre->next;
        carry = tmp / 10;
    }
    if(carry) {
        pre->next = new ListNode(carry);
    }
    return dummyhead->next;
}



int main() {



    return 0;
}