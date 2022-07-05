class Solution {
public:
    bool isSubsequence(string s, string t) {
        int size_s = s.size();
        int size_t = t.size();
        if(size_s==0){
            return true;
        }
        int j = 0;
        for(int i = 0; i < size_t; i++){
            if(s[j]==t[i]){
                j++;
            }
            if(j==size_s){
                return true;
            }
        }
        return false;
    }
};