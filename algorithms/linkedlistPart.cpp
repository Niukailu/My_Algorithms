#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

//链表专题
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* removeElements(ListNode* head, int val) {
    ListNode* dummyhead = new ListNode(0);
    dummyhead->next = head;
    ListNode* pre = dummyhead;
    while (pre->next)
    {
        if(pre->next->val == val) {
            ListNode* node = pre->next;
            pre->next = node->next;
            delete node;
        }
        else pre = pre->next;
    }
    return dummyhead->next;
}
//设计链表
class MyLinkedList {
private:
    ListNode *dummyhead;
    int len;
public:
    MyLinkedList() {
        dummyhead = new ListNode(0);
        len = 0;
    }
    int get(int index) {
        if(index < 0 || index >= len) return -1;
        ListNode* cur = dummyhead;
        index++;
        while (index--)
        {
            cur = cur->next;
        }
        return cur->val;
    }
    
    void addAtHead(int val) {
        ListNode* node = new ListNode(val);
        node->next = dummyhead->next;
        dummyhead->next = node;
        len++;
    }
    
    void addAtTail(int val) {
        ListNode* tail = dummyhead;
        while (tail->next)
        {
            tail = tail->next;
        }
        tail->next = new ListNode(val);
        len++;
    }
    
    void addAtIndex(int index, int val) {
        if(index < 0) addAtHead(val);
        else if(index == len) addAtTail(val);
        else if(index > len) return;
        else {
            ListNode* cur = dummyhead;
            while (index--)
            {
                cur = cur->next;
            }
            ListNode* node = new ListNode(val);
            node->next = cur->next;
            cur->next = node;
            len++;
        }
    }
    
    void deleteAtIndex(int index) {
        if(index >=0 && index < len) {
            ListNode* cur = dummyhead;
            while (index--)
            {
                cur = cur->next;
            }
            ListNode* node = cur->next;
            cur->next = cur->next->next;
            delete node;
            len--;
        }
    }
};
//反转链表
ListNode* reverseList(ListNode* head) { //迭代(从前往后翻)
    ListNode* pre = nullptr;
    ListNode* cur = head;
    while (cur)
    {
        ListNode* next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    return pre;
}
ListNode* reverseList(ListNode* head) { //递归(从后往前翻)
    if(!head || !head->next) return head;
    ListNode* newhead = reverseList(head->next);
    head->next->next = head;
    head->next = nullptr;
    return newhead;
}
ListNode* swapPairs(ListNode* head) {
    ListNode* dummyhead = new ListNode(0);
    dummyhead->next = head;
    ListNode *pre = dummyhead, *cur = head;
    while (cur && cur->next)
    {
        ListNode* node = cur->next;
        cur->next = node->next;
        node->next = cur;
        pre->next = node;
        pre = cur;
        cur = cur->next;
    }
    return dummyhead->next;
}
ListNode* removeNthFromEnd(ListNode* head, int n) {
    if(!head) return nullptr;
    ListNode* dummyhead = new ListNode(0);
    dummyhead->next = head;
    ListNode *quick = dummyhead, *slow = dummyhead;
    while (n--)
    {
        quick = quick->next;
    }
    while (quick->next)
    {
        quick = quick->next;
        slow = slow->next;
    }
    ListNode* node = slow->next;
    slow->next = slow->next->next;
    delete node;
    return dummyhead->next;
}
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *a = headA, *b = headB;
    while (a != b)
    {
        a = a == nullptr ? headB : a->next;
        b = b == nullptr ? headA : b->next;
    }
    return a;
}
ListNode *detectCycle(ListNode *head) {
    ListNode *quick = head, *slow = head;
    while (quick && quick->next)
    {
        quick = quick->next->next;
        slow = slow->next;
        if(quick == slow) {
            quick = head;
            while (quick != slow)
            {
                quick = quick->next;
                slow = slow->next;
            }
            return quick;
        }
    }
    return NULL;        
}