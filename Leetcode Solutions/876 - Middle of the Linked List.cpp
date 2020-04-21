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
    int sz;
    int cnt;
    ListNode* middleNode(ListNode* head) {
        ListNode* ans = head;
        if(head->next != nullptr){
            sz++;
            ans = middleNode(head->next);
            ++cnt;
        }
        if(cnt == sz/2) ans = head;
        return ans;
    }
};