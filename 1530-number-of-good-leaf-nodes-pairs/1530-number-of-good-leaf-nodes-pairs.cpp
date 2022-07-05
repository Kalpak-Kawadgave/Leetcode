vector<string> vs;

void visit(TreeNode* Node,string s){
    string y=s;
    if(Node->left!=nullptr){
        s+="0";
        visit(Node->left,s);
    }
    if(Node->right!=nullptr){
        y+="1";
        visit(Node->right,y);
    }
    if(Node->left==nullptr&&Node->right==nullptr){
        vs.push_back(s);
    }
    return;
}

int stringcheck(string s1, string s2){
    int l1,l2;
    l1 = s1.size();
    l2 = s2.size();
    int i = 0;
    while(s1[i]==s2[i]){
        i++;
    }
    return l1+l2-2*i;
}

class Solution {
public:
    int countPairs(TreeNode* root, int distance) {
        if(root->left==nullptr&&root->right==nullptr){
            return 0;
        }
        int ans = 0;
        int abc = 0;
        string s = "";
        visit(root,s);
        int size = vs.size();
        for(int i = 0; i < size - 1; i++){
            for(int j = i+1; j < size; j++){
                abc = stringcheck(vs[i],vs[j]);
                if(abc <= distance){
                    ans += 1;
                }
            }
        }
        vs.clear();
        return ans;
    }
};