#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

vector<int> inorderTraversal(TreeNode* root) {
    vector<int> res;
    stack<TreeNode*> stk;
    if(root != nullptr) stk.push(root);
    while (!stk.empty())
    {
        TreeNode *cur = stk.top();
        stk.pop();
        if(cur != nullptr) {
            if(cur->right != nullptr) stk.push(cur->right);
            stk.push(cur);
            stk.push(nullptr);
            if(cur->left != nullptr) stk.push(cur->left);
        }
        else {
            res.push_back(stk.top()->val);
            stk.pop();
        }
    }
    return res;
}

vector<vector<int>> Print(TreeNode* pRoot) {
    vector<vector<int>> res;
    deque<TreeNode*> que;
    if(pRoot != nullptr) que.push_back(pRoot);
    bool flag = true;
    while (!que.empty())
    {
        vector<int> it;
        int len = que.size();
        for (int i = 0; i < len; i++)
        {
            if(flag) {
                TreeNode *cur = que.back();
                it.push_back(cur->val);
                que.pop_back();
                if(cur->left != nullptr) que.push_front(cur->left);
                if(cur->right != nullptr) que.push_front(cur->right);
            }
            else {
                TreeNode *cur = que.front();
                it.push_back(cur->val);
                que.pop_front();
                if(cur->right != nullptr) que.push_back(cur->right);
                if(cur->left != nullptr) que.push_back(cur->left);
            }
        }
        flag = !flag;
        res.push_back(it);
    }
    return res;
}

bool hasPathSum(TreeNode* root, int sum) {
    if(root == nullptr) return false;
    if(root->left == nullptr && root->right == nullptr) {
        if(sum == root->val) return true;
        return false;
    }
    if(root->left != nullptr) {
        if(hasPathSum(root->left, sum - root->val)) return true;
    }
    if(root->right != nullptr) {
        if(hasPathSum(root->right, sum - root->val)) return true;
    }
    return false;
}

TreeNode *pre = nullptr, *res = nullptr;
void getList(TreeNode* pRootOfTree) {     //二叉搜索树与双向链表
    if(pRootOfTree == nullptr) return;
    getList(pRootOfTree->left);
    if(pre != nullptr) pre->right = pRootOfTree;
    pRootOfTree->left = pre;
    pre = pRootOfTree;
    if(res == nullptr) res = pRootOfTree;
    getList(pRootOfTree->right);
}
TreeNode* Convert(TreeNode* pRootOfTree) {
    getList(pRootOfTree);
    return res;
}

TreeNode* Mirror(TreeNode* pRoot) {
    if(pRoot == nullptr) return nullptr;
    TreeNode *left = Mirror(pRoot->left);
    TreeNode *right = Mirror(pRoot->right);
    pRoot->left = right;
    pRoot->right = left;
    return pRoot;
}

bool isCompleteTree(TreeNode* root) {
    queue<TreeNode*> que;
    if(root != nullptr) que.push(root);
    bool flag = false;
    while (!que.empty())
    {
        int len = que.size();
        for (int i = 0; i < len; i++)
        {
            TreeNode *cur = que.front();
            que.pop();
            if(cur->left == nullptr && cur->right == nullptr) {
                flag = true;
            }
            else {
                if(flag) return false;
                if(cur->left == nullptr && cur->right != nullptr) return false;
                if(cur->left != nullptr && cur->right == nullptr) flag = true;
                if (cur->left != nullptr) que.push(cur->left);
                if (cur->right != nullptr) que.push(cur->right);
            }
        } 
    }
    return true;   
}

int getDepth(TreeNode* root) {
    if(root == nullptr) return 0;
    int left = getDepth(root->left);
    if(left == -1) return -1;
    int right = getDepth(root->right);
    if(right == -1) return -1;
    return abs(left - right) > 1 ? -1 : max(left, right) + 1;
}
bool IsBalanced_Solution(TreeNode* pRoot) {                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         
    return getDepth(pRoot) != -1;
}

int lowestCommonAncestor(TreeNode* root, int p, int q) {
    if(root == nullptr) return -1;
    if(root->val > p && root->val > q) return lowestCommonAncestor(root->left, p, q);
    if(root->val < p && root->val < q) return lowestCommonAncestor(root->right, p, q);
    return root->val;
}

int lowestCommonAncestor(TreeNode* root, int o1, int o2) {
    if(root == nullptr) return -1;
    if(root->val == o1 || root->val == o2) return root->val;
    int left = lowestCommonAncestor(root->left, o1, o2);
    int right = lowestCommonAncestor(root->right, o1, o2);
    if(left != -1 && right != -1) return root->val;
    if(left != -1) return left;
    return right;
}

class Solution {
private:
    int getnum(char*& str) {
        if(*str == '#') {
            str += 2;
            return -1;
        }
        int num = 0;
        while(*str != '\0' && *str != ',') {
            num = num * 10 + (*str - '0');
            ++str;
        }
        if(*str == ',') ++str;
        return num;
    }

public:
    char* Serialize(TreeNode *root) {
        if(root == nullptr) return nullptr;    
        string res = "";
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty())
        {
            int len = que.size();
            for (int i = 0; i < len; i++)
            {
                TreeNode *cur = que.front();
                que.pop();
                if(cur == nullptr) res += "#,";
                else {
                    res += to_string(cur->val) + ',';
                    que.push(cur->left);
                    que.push(cur->right);
                }
            }
        }
        res.pop_back();
        char* c = new char[res.length() + 1];
        strcpy(c, res.c_str());
        return c;
    }

    TreeNode* Deserialize(char *str) {
        if(str == nullptr) return nullptr;
        int num = getnum(str);
        TreeNode *root = new TreeNode(num);
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty() && *str != '\0')
        {
            TreeNode *cur = que.front();
            que.pop();
            if(cur == nullptr) continue;
            int left = getnum(str);
            if(left != -1) cur->left = new TreeNode(left);
            int right = getnum(str);
            if(right != -1) cur->right = new TreeNode(right);
            que.push(cur->left);
            que.push(cur->right);
        }
        return root;
    }
};

TreeNode* _reConstructBinaryTree(vector<int>& pre,vector<int>& vin, int left, int right, int mid) {
    if(left > right) return nullptr;
    TreeNode* root = new TreeNode(pre[mid]);
    int idx = left;
    while(idx <= right && vin[idx] != pre[mid]) ++idx;
    root->left = _reConstructBinaryTree(pre, vin, left, idx - 1, mid + 1);
    root->right = _reConstructBinaryTree(pre, vin, idx + 1, right, mid + idx - left + 1);
    return root;
}

TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
    return _reConstructBinaryTree(pre, vin, 0, vin.size() - 1, 0);
}




