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
void treeadd(int* ans, string number,TreeNode * current){
    if(current->left == nullptr&&current->right==nullptr){
        number+=to_string(current->val);
        *ans+=stoi(number);
    }
    else{
        number+=to_string(current->val);
        if(current->left != nullptr){
            treeadd(ans,number,current->left);
        }        
        if(current->right != nullptr){
            treeadd(ans,number,current->right);
        }
    }
}

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        int ans = 0;
        treeadd(&ans,"",root);
        return ans;
    }
};