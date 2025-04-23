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
        int sum = 0;  // Use signed int to handle negative values too
        convertToGst(root, sum);
        return root;
    }

private:
    // Performs reverse in-order traversal (right → node → left)
    void convertToGst(TreeNode* node, int& sum) {
        if (!node) return;

        convertToGst(node->right, sum);  // Traverse right subtree

        sum += node->val;                // Accumulate and update value
        node->val = sum;

        convertToGst(node->left, sum);   // Traverse left subtree
    }
};