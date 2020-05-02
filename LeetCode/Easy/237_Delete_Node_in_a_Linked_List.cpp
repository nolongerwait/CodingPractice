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
    void deleteNode(ListNode* node) {
        // change the value of node to next node
        node -> val = node -> next -> val;
        
        // change the next of node to next node, and delete the next pointer
        ListNode* p = node -> next;
        node -> next = node -> next -> next;
        delete p;
    }
};