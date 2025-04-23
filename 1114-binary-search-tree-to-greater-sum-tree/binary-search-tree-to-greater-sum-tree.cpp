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
    TreeNode* bstToGst(TreeNode* root) {
        unsigned int sum = 0;  
        updateBstNode(*root, sum);
        return root;
    }

    void updateBstNode(TreeNode &node, unsigned int& sum ){
        if(node.right!=nullptr){
            updateBstNode( *node.right, sum);
        }
        sum += node.val;
        node.val=sum;
        if(node.left!=nullptr){
            updateBstNode(*node.left, sum);
        }
    }

};