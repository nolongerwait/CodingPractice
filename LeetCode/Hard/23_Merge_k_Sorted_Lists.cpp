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
    ListNode* merge(ListNode* p1, ListNode* p2) {
        if(p1 == nullptr) return p2;
        if(p2 == nullptr) return p1;

        if(p1->val > p2->val) {
            p2->next = merge(p2->next, p1);
            return p2;
        }
        else {
            p1->next = merge(p2, p1->next);
            return p1;
        }
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;
        ListNode* head = lists[0];
        for(int i = 1; i < lists.size(); ++i) {
            if(lists[i] != nullptr) {
                head = merge(head, lists[i]);
            }
        }
        return head;
    }
};