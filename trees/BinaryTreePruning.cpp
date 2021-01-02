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
    /*
     * What I want to do here is that prune both halves of the tree. 
     * We return null if no node in the sub half has 1. 
     * If the root has 1, we cannot simply return root because, then recursion 
     * cannot prune the remaining tree. Only, if none of the subtrees has node with value 1,
     * then only we return root if it has node with value 1.
     */
    TreeNode* pruneTree(TreeNode* root) {
        if(!root || ((!root->left && !root->right) && root->val == 0))
            return nullptr;
        // First we prune the sub trees
        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);
        /*
         * If, either of them is present, means that they have a node with val 1
         * which means that the main tree also has a node with val 1
         * So, we can return root if either of the sub trees is not nullptr
         */
        if(root->left || root->right)
            return root;
        else
            return root->val == 1 ? root : nullptr ;
    }
};