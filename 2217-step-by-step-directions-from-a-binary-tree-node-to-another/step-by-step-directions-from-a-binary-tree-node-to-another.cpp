class Solution {
public:
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string pathToStart, pathToDest;
        string path;
        path.reserve(100000);  // optional optimization

        findPaths(root, startValue, destValue, path, pathToStart, pathToDest);

        // Find divergence point
        int i = 0;
        while (i < pathToStart.size() && i < pathToDest.size() && pathToStart[i] == pathToDest[i]) {
            ++i;
        }

        // Go up from startValue to the LCA
        string result(pathToStart.size() - i, 'U');
        // Go down from LCA to destValue
        result += pathToDest.substr(i);
        return result;
    }

private:
    bool findPaths(TreeNode* node, int startValue, int destValue, string& path, string& pathToStart, string& pathToDest) {
        if (!node) return false;

        if (node->val == startValue) {
            pathToStart = path;
        }
        if (node->val == destValue) {
            pathToDest = path;
        }
        if (!pathToStart.empty() && !pathToDest.empty()) return true;

        path.push_back('L');
        if (findPaths(node->left, startValue, destValue, path, pathToStart, pathToDest)) return true;
        path.pop_back();

        path.push_back('R');
        if (findPaths(node->right, startValue, destValue, path, pathToStart, pathToDest)) return true;
        path.pop_back();

        return false;
    }
};
