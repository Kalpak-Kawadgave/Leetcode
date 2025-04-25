
class Solution {
public:
    string s, t;
    
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string path;
        getPathToStartDest(root, startValue, destValue, path);
        
        int i = 0;
        while (i < s.size() && i < t.size() && s[i] == t[i]) {
            ++i;
        }

        string ans(s.size() - i, 'U');  // go up from startValue to LCA
        ans += t.substr(i);             // go down from LCA to destValue

        return ans;
    }

    bool getPathToStartDest(TreeNode* node, int startValue, int destValue, string& path) {
        if (!node) return false;

        if (node->val == startValue) {
            s = path;
        }
        if (node->val == destValue) {
            t = path;
        }

        if (!s.empty() && !t.empty()) return true;

        path.push_back('L');
        if (getPathToStartDest(node->left, startValue, destValue, path)) return true;
        path.pop_back();

        path.push_back('R');
        if (getPathToStartDest(node->right, startValue, destValue, path)) return true;
        path.pop_back();

        return false;
    }
};
