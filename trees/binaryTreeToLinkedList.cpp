/**
 * https://leetcode.com/problems/flatten-binary-tree-to-linked-list/submissions/
 *
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
    pair<TreeNode*, TreeNode*> helper(TreeNode* root) { 
        if(!root || (!root->left && !root->right))
            return {root, root};
        
        pair<TreeNode*, TreeNode*> lAns = helper(root->left);
        pair<TreeNode*, TreeNode*> rAns = helper(root->right);
        
        if(root->left && !root->right) {
            root->right = lAns.first;
            root->left = nullptr;
            return {root, lAns.second};
        }
        else if(!root->left && root->right){
            root->right = rAns.first;
            root->left = nullptr;
            return {root, rAns.second};
        }
        else {
            root->right = lAns.first;
            root->left = nullptr;

            lAns.second->right = rAns.first;            
            return {root, rAns.second};
        }
            
    }
    void flatten(TreeNode* root) {
        root = helper(root).first;
    }
};