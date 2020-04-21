//https://leetcode.com/problems/increasing-order-search-tree/
//897. Increasing Order Search Tree
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* cur;
    vector<int> v;
    void dfs(TreeNode* root){
        if(root == NULL) return;
        dfs(root->left);
        v.push_back(root->val);
        dfs(root->right);;
    }
    
    TreeNode* increasingBST(TreeNode* root) {
        dfs(root);
        TreeNode* ans = new TreeNode(0);
        cur = ans;
        for(int x : v){
            cur->right = new TreeNode(x);
            cur = cur->right;
        }
        return ans->right;
    }
};