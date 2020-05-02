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
        stack<int> sl1, sl2;
        while(l1 != nullptr) {
            sl1.push(l1->val);
            l1 = l1->next;
        }
        while(l2 != nullptr) {
            sl2.push(l2->val);
            l2 = l2->next;
        }

        int carry = 0;
        ListNode* res = nullptr;
        while(!sl1.empty() || !sl2.empty() || carry != 0) {
            int first = sl1.empty() ? 0 : sl1.top();
            int second = sl2.empty() ? 0 : sl2.top();

            if(!sl1.empty()) sl1.pop();
            if(!sl2.empty()) sl2.pop();

            int current = first + second + carry;
            carry = current / 10;
            current = current % 10;

            ListNode* pCurrent = new ListNode(current);
            pCurrent->next = res;
            res = pCurrent;
        }
        return res;
    }
};