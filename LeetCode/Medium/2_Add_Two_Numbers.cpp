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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr) return l2;
        if(l2 == nullptr) return l1;
        int carry = (l1->val + l2->val) / 10;
        ListNode* head = new ListNode((l1->val + l2->val) % 10);
        ListNode* p = head;
        l1 = l1->next;
        l2 = l2->next;
        while(l1!= nullptr || l2!= nullptr || carry != 0) {
            int sum = 0;
            if(l1 == nullptr && l2 == nullptr) sum = carry;
            else if(l1 == nullptr) sum = l2->val + carry;
            else if(l2 == nullptr) sum = l1->val + carry;
            else sum = l1->val + l2->val + carry;

            carry = sum / 10;
            sum %= 10;

            p->next = new ListNode(sum);
            p = p->next;

            if(l1 != nullptr) l1 = l1->next;
            if(l2 != nullptr) l2 = l2->next;
        }
        return head;        
    }
};