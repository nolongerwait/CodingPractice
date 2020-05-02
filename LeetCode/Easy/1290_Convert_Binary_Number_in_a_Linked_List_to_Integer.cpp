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
    int getDecimalValue(ListNode* head) {
        vector<int> numbers;

        ListNode* pointer = head;
        while(pointer != NULL){
            numbers.push_back(pointer -> val);
            pointer = pointer -> next;
        }
        int ret = 0;
        for(int i =0;i < numbers.size();i++){
            ret = ret*2 + numbers[i];
        }

        return ret;
    }
};