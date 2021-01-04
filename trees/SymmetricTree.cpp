/**
 * https://leetcode.com/problems/symmetric-tree/
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
    /*
     * A tree is symmetric iff it is a mirror of itself.
     * Two trees are mirrors of each other when 
     * 1. the right subtree of first is the mirror of left subtree of the second
     * 2. the left subtree of first is the mirror of right subtree of the second
     * 3. the value of root of both the trees is same 
     */
    bool mirrorTrees(TreeNode* a, TreeNode* b) {
        if(!a && !b)
            return true;
        if(!a || !b)
            return false;
        return a->val == b->val && mirrorTrees(a->left, b->right) && mirrorTrees(a->right, b->left); 
    }
        
    bool isSymmetric(TreeNode* root) {
        return mirrorTrees(root, root);
    }
};