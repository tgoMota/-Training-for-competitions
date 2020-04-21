//https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/
//1290. Convert Binary Number in a Linked List to Integer
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int gr = 0;
    int getDecimalValue(ListNode* head) {
        return head == NULL ? 0 : getDecimalValue(head->next) + (1<<gr++)*(head->val);
    }
};