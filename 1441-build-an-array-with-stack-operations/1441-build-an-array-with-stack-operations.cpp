class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        int count = 1;
        for(int c: target){
            while(c!=count){
                ans.push_back("Push");
                ans.push_back("Pop");
                count++;
            }
            if (c==count){
                ans.push_back("Push");
                count++;
            }
        }
        return ans;
    }
};