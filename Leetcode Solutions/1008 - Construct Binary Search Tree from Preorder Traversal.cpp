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
    int index = 0;
    TreeNode* bstFromPreorder(vector<int>& preorder, int pvalue = INT_MAX) {
        if(index == preorder.size() || preorder[index] > pvalue) return NULL;
        int val = preorder[index++];
        TreeNode* t = new TreeNode(val);
        t->left = bstFromPreorder(preorder,val);
        t->right = bstFromPreorder(preorder, pvalue);
        return t;
    }
};