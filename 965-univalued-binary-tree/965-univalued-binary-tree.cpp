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
    int v;
    bool isUnivalTree(TreeNode* root) {
        v = root->val;
        return UnivalTree(root);
    }    
    bool UnivalTree(TreeNode* root) {
        if(root==nullptr) return true;
        if(root->val!=v) return false;
        return (UnivalTree(root -> left)&&UnivalTree(root->right));
    }
};