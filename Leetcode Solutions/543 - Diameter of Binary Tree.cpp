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
    int mxsum;
    int dfs(TreeNode* root){
        int left = 0, right = 0;
        if(root->left != nullptr) left= 1+dfs(root->left);
        if(root->right != nullptr) right = 1+dfs(root->right);
        mxsum = max(mxsum, left+right);
        return max(left, right);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        if(root != nullptr) dfs(root);
        return mxsum;
    }
};