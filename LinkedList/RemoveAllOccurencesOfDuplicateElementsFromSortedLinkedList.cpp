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
    bool isUnique(ListNode* head) {
        return !head->next || head->val != head->next->val;
    }
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next)
            return head;
        ListNode* output = nullptr;
        ListNode* outputTail = nullptr;

        while(head) {
            if(isUnique(head)) {
                if(output == nullptr) {
                    output = outputTail = head;
                } else {
                    outputTail->next = head;
                    outputTail = outputTail->next;
                }
                head = head->next;
                outputTail->next = nullptr;
                continue;
            }
            while(!isUnique(head)) {
                head = head->next;
            }
            head = head->next;
        }

        return output;
        
    }
};