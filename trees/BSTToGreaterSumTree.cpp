/**
 * https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/
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
     * Since the given tree is a BST, what I will do is do a reverse inorder traversal 
     * (Right Child -> Root -> Left Child)to process the elements in decreasing order.
     * When I process the each element, I add its value to sum variable for adding to smaller elements.  
     * For the largest element, the sum added to it will be 0 and for other, the sum variable
     * will contain the sum of all greater numbers which are processed already.
     */
    void reArrange(TreeNode* root, int& sum) {
        if(!root)
            return;
        
        reArrange(root->right, sum);
        
        sum += root->val;
        root->val = sum;
        
        reArrange(root->left, sum);

    }
    TreeNode* bstToGst(TreeNode* root) {
        int sum = 0;
        reArrange(root, sum);
        return root;
    }
};