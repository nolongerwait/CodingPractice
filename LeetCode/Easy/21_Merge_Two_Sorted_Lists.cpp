/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* p1, ListNode* p2) {
        if(p1 == nullptr) return p2;
        if(p2 == nullptr) return p1;

        if(p1->val > p2->val) {
            p2->next = mergeTwoLists(p2->next, p1);
            return p2;
        }
        else {
            p1->next = mergeTwoLists(p2, p1->next);
            return p1;
        }
    }
};