//https://leetcode.com/problems/linked-list-in-binary-tree/
//1367. Linked List in Binary Tree
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    bool dfs2(ListNode* head, TreeNode* root){
        if(head == NULL) return true;
        if(root == NULL) return false;
        if(head->val == root->val) return (dfs2(head->next, root->left) || dfs2(head->next, root->right));
        return false;
    }
    bool dfs(ListNode* head, TreeNode* root){
        if(root == NULL) return false;
        if(root->val == head->val && dfs2(head, root)) return true;
        if(dfs(head, root->left) || dfs(head,root->right)) return true;
        return false;
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        return dfs(head,root);
    }
};