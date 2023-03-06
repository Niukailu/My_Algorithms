#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_set>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
vector<int> nums;
void preTree(TreeNode* root) { //递归
    if(!root) return;
    nums.push_back(root->val);
    preTree(root->left);
    preTree(root->right);
}
vector<int> preorderTraversal2(TreeNode* root) {
    preTree(root);
    return nums;
}
vector<int> preorderTraversal(TreeNode* root) { //迭代-前序
    vector<int> res;
    stack<TreeNode*> stk;
    if(root) stk.push(root);
    while (!stk.empty())
    {
        TreeNode* cur = stk.top();
        stk.pop();
        if(cur->right) stk.push(cur->right);
        if(cur->left) stk.push(cur->left); 
        res.push_back(cur->val);
    }
    return res;
}
vector<int> inorderTraversal(TreeNode* root) { //迭代-中序(统一写法)
    vector<int> res;
    stack<TreeNode*> stk;
    if(root) stk.push(root);
    while (!stk.empty())
    {
        TreeNode* cur = stk.top();
        if(cur) {
            stk.pop();
            if(cur->right) stk.push(cur->right); //右
            stk.push(cur);
            stk.push(nullptr);                  //中
            if(cur->left) stk.push(cur->left); //左
        }
        else {
            stk.pop();
            res.push_back(stk.top()->val);
            stk.pop();
        }
    }
    return res;
}
vector<int> postorderTraversal(TreeNode* root) {//迭代-后序(统一写法)
    vector<int> res;
    stack<TreeNode*> stk;
    if(root) stk.push(root);
    while (!stk.empty())
    {
        TreeNode* cur = stk.top();
        if(cur) {
            stk.push(nullptr);                  //中
            if(cur->right) stk.push(cur->right); //右
            if(cur->left) stk.push(cur->left); //左
        }
        else {
            stk.pop();
            res.push_back(stk.top()->val);
            stk.pop();
        }
    }
    return res;
}
vector<vector<int>> levelOrder(TreeNode* root) { //层序
    vector<vector<int>> res;
    queue<TreeNode*> que;
    if(root) que.push(root);
    while (!que.empty())
    {
        vector<int> level;
        int len = que.size();
        for (int i = 0; i < len; i++)
        {
            TreeNode* cur = que.front();
            que.pop();
            level.push_back(cur->val);
            if(cur->left) que.push(cur->left);
            if(cur->right) que.push(cur->right);
        }
        res.push_back(level);
    }
    return res;
}
TreeNode* invertTree(TreeNode* root) { //反转二叉树
    if(!root) return nullptr;
    TreeNode* left = invertTree(root->left);
    TreeNode* right = invertTree(root->right);
    root->left = right;
    root->right = left;
    return root;
}

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
};
Node* connect(Node* root) {
    if(!root) return nullptr;
    if(root->left) root->left->next = root->right;
    if(root->right && root->next) root->right->next = root->next->left;
    connect(root->left);
    connect(root->right);
    return root;
}
Node* connect2(Node* root) { //O(1)空间
    Node* cur = root;
    while (cur)
    {
        Node* dummynode = new Node();
        Node* pre = dummynode;
        while (cur)
        {
            if(cur->left) {
                pre->next = cur->left;
                pre = pre->next;
            }
            if(cur->right) {
                pre->next = cur->right;
                pre = pre->next;
            }
            cur = cur->next;
        }
        cur = dummynode->next;
    }
    return root;
}
int maxDepth(TreeNode* root) {
    if(!root) return 0;
    return max(maxDepth(root->left), maxDepth(root->right)) + 1; 
}
int minDepth(TreeNode* root) {
    if(!root) return 0;
    else if(!root->left && !root->right) return 1;
    else if(root->left && !root->right) return minDepth(root->left) + 1;
    else if(!root->left && root->right) return minDepth(root->right) + 1;
    else return min(minDepth(root->left), minDepth(root->right)) + 1;
}
//对称二叉树
bool isequal2(TreeNode* left, TreeNode* right) {
    if(!left && !right) return true;
    if(left && right) {
        if(left->val != right->val) return false;
        return isequal2(left->left, right->right) && isequal2(left->right, right->left);
    }
    return false;
}
bool isSymmetric(TreeNode* root) {
    if(!root) return true;
    return isequal(root->left, root->right);
}
//判断是否是子树
bool isequal(TreeNode* left, TreeNode* right) {
    if(!left && !right) return true;
    if(left && right) {
        if(left->val != right->val) return false;
        return isequal(left->left, right->left) && isequal(left->right, right->right);
    }
    return false;
}
bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    if(!root) return false;
    if(isSubtree(root->left, subRoot)) return true;
    if(isSubtree(root->right, subRoot)) return true;
    return isequal(root, subRoot);
}
int countNodes(TreeNode* root) { //O(logn * logn)
    if(!root) return 0;
    int cnt1 = 1;
    TreeNode* cur1 = root;
    while (cur1->left)
    {
        ++cnt1;
        cur1 = cur1->left;
    }
    int cnt2 = 1;
    TreeNode* cur2 = root;
    while (cur2->right)
    {
        ++cnt2;
        cur2 = cur2->right;
    }
    if(cnt1 == cnt2) return (1 << cnt1) - 1;
    return countNodes(root->left) + countNodes(root->right) + 1;
}
int depth(TreeNode* root) {
    if(!root) return 0;
    int l = depth(root->left); 
    int r = depth(root->right);
    if(l == -1 || r == -1) return -1;
    if(abs(l - r) > 1) return -1;
    return max(l, r) + 1;
}
bool isBalanced(TreeNode* root) {
    return depth(root) != -1;
}
int sumOfLeftLeaves(TreeNode* root) {
    if(!root) return 0;
    if(!root->left && !root->right) return 0;
    int sum = 0;
    if(root->left) {
        if(!root->left->left && !root->left->right) sum += root->left->val;
    }
    sum += sumOfLeftLeaves(root->left);
    sum += sumOfLeftLeaves(root->right);
    return sum;
}
int getmaxDepth(TreeNode* root) {
    if(!root) return 0;
    return max(maxDepth(root->left), maxDepth(root->right)) + 1; 
}
//513. 找树左下角的值
int max_dp = 0;
int res = 0;
void dfs(TreeNode* root, int cur_dp) {
    if(!root) return;
    cur_dp++;
    if(!root->left && !root->right) {
        if(cur_dp > max_dp) {
            max_dp = cur_dp;
            res = root->val;
        }
        return;
    }
    dfs(root->left, cur_dp);
    dfs(root->right, cur_dp);
}
int findBottomLeftValue(TreeNode* root) {
    dfs(root, 0);
    return res;
}
//构造二叉树(中序+后序)
TreeNode* bulid(vector<int>& inorder, vector<int>& postorder, int left, int right, int root_idx) {
    if(right - left < 0) return nullptr;
    int midnum = postorder[root_idx];
    TreeNode* root = new TreeNode(midnum);
    int idx = left;
    while (idx <= right && inorder[idx] != midnum)
    {
        ++idx;
    }
    root->left = bulid(inorder, postorder, left, idx - 1, root_idx - right + idx - 1);
    root->right = bulid(inorder, postorder, idx + 1, right, root_idx - 1);
    return root;
}
TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    return bulid(inorder, postorder, 0, inorder.size() - 1, postorder.size() - 1);
}
vector<int> nums;
bool isValidBST2(TreeNode* root) { //验证二叉搜索树
    if(!root) return true;
    if(!isValidBST(root->left)) return false;
    if(nums.size() > 0 && root->val <= nums[nums.size() - 1]) return false;
    nums.push_back(root->val);
    if(!isValidBST(root->right)) return false;
    return true;
}
TreeNode *pre = nullptr;
bool isValidBST(TreeNode* root) { //双指针法
    if(!root) return true;
    if(!isValidBST(root->left)) return false;
    if(pre && root->val <= pre->val) return false;
    pre = root;
    if(!isValidBST(root->right)) return false;
    return true;
}
//找众数
vector<int> ans;
int maxnum = 0, cnt = 0;
TreeNode* pre = nullptr;
void dfs(TreeNode* root) {
    if(!root) return;
    dfs(root->left);
    if(pre && root->val != pre->val) cnt = 1;
    else ++cnt;
    if(cnt > maxnum) {
        maxnum = cnt;
        ans.clear();   
    }
    if(cnt == maxnum) ans.push_back(root->val);
    pre = root;
    dfs(root->right);
}
vector<int> findMode(TreeNode* root) {
    dfs(root);
    return ans;
}
//236. 二叉树的最近公共祖先
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(!root || root == p || root == q) return root;
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);
    if(left && right) return root;
    if(left && !right) return left;
    if(!left && right) return right;
    return nullptr;
}
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) { //二叉搜索树
    if(!root || root == p || root == q) return root;  
    if(p->val < root->val && q->val < root->val) return lowestCommonAncestor(root->left, p, q);
    else if(p->val > root->val && q->val > root->val) return lowestCommonAncestor(root->right, p, q);
    else return root;
}
//二叉搜索树插入节点
TreeNode* insertIntoBST(TreeNode* root, int val) {
    if(!root) return new TreeNode(val);
    if(val < root->val) root->left = insertIntoBST(root->left, val);
    if(val > root->val) root->right = insertIntoBST(root->right, val);
    return root;
}
//二叉搜索树删除节点
TreeNode* deleteNode(TreeNode* root, int key) {
    if(!root) return nullptr;
    if(root->val == key) {
        TreeNode* node = root;
        if(!root->left && !root->right) root = nullptr;
        else if(root->left && !root->right) root = root->left;
        else if(!root->left && root->right) root = root->right;
        else {
            TreeNode* cur = root->left;
            while (cur->right)
            {
                cur = cur->right;
            }
            cur->right = root->right;
            root = root->left;
        }
        delete node;
    }
    else if(root->val > key) root->left = deleteNode(root->left, key);
    else root->right = deleteNode(root->right, key); 
    return root;
}
TreeNode* trimBST(TreeNode* root, int low, int high) {
    if(!root) return nullptr;
    if(low > root->val) return trimBST(root->right, low, high);
    if(high < root->val) return trimBST(root->left, low, high);
    root->left = trimBST(root->left, low, high);
    root->right = trimBST(root->right, low, high);
    return root;
}
//
TreeNode* pre = nullptr;
TreeNode* convertBST(TreeNode* root) {
    if(!root) return nullptr;
    convertBST(root->right);
    if(pre) {
        root->val += pre->val;
    }
    pre = root;
    convertBST(root->left); 
    return root;
}



