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
    pair<ListNode*, ListNode*> reverse(ListNode* head) {
        if(!head || !head->next)
            return {head, head};
        ListNode *prev = nullptr, *current = head, *next = head->next; 
        while(current->next) {
            current->next = prev;
            prev = current;
            current = next;
            next = next->next;
        }
        current->next = prev;    
        return {current, head};
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        // return reverse(head).first;
        int nodes = 1;
        ListNode* dummy = head;
        while(dummy && nodes < k){
            dummy = dummy->next;
            nodes++;
        }
        if(!dummy)
            return head;
        
        ListNode* remaining = reverseKGroup(dummy->next, k);
        dummy->next = nullptr;
        pair<ListNode*, ListNode*> output = reverse(head);
        output.second->next = remaining;
        return output.first;
    }
};