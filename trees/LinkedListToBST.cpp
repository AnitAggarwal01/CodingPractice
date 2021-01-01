/**
 * https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/submissions/
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    TreeNode* createTreeNodeFromListNode(ListNode* listNode) {
        return new TreeNode(listNode->val);
    }
    
    ListNode* findMidLeft(ListNode* head) {
        ListNode *fast = head, *slow = head, *slowLeft = nullptr;
        while(fast) {
            fast = fast -> next;
            if(fast) {
                slowLeft = slow;
                slow = slow->next;
                fast = fast->next;
            }
        }
        return slowLeft;
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head) { 
            return nullptr;
        }
        
        if(!head->next){
            return createTreeNodeFromListNode(head); 
        }
        
        ListNode* midLeft = findMidLeft(head);
        ListNode*mid = midLeft->next;
        midLeft->next = nullptr;
        
        TreeNode* root = createTreeNodeFromListNode(mid);
        
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(mid->next);
        
        return root;
    }
};