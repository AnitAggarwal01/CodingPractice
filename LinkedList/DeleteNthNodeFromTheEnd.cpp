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
    /*
     * If the node to be deleted isn't the last node, we can delete it by just knowing its address
     * We put the data of node's next into the targetNode(to be deleted) and then make the targetNode
     * point to 2nd node after it. This will cover cases where where node position is not last.
     *
     * If the last node is to be deleted, we just traverse to the end, and get the address of the penultimate node
     * Then we make it's nect pointer, to point to a nullptr rather than the last node.
     */
    ListNode* removeLastNode(ListNode* head) {
        if(!head || !head->next)
            return nullptr;
        ListNode* temp = head;
        while(temp->next->next) {
            temp = temp->next;
        }
        temp->next = nullptr;
        return head;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(n == 1) {
            return removeLastNode(head);
        }    
        ListNode* target = head;
        ListNode* leadingNode = head;
        int distance = 0;
        while(distance < n) {
            if(leadingNode)
                leadingNode = leadingNode->next;
            distance++;
        }
        while(leadingNode) {
            leadingNode = leadingNode->next;
            target = target->next;
        }
        target->val = target->next->val;
        target->next = target->next->next;
        
        return head;
    }
};