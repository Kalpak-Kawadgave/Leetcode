class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> alpha1(26,0);
        vector<int> alpha2(26,0);
        size_t size = s.size(); 
        ++alpha2[t[size]-97];
        for(int i = 0; i < size; ++i){
            ++alpha1[s[i]-97];
            ++alpha2[t[i]-97];
        }
        int i;
        for(i = 0; i < 26; ++i){
            if(alpha1[i]!=alpha2[i]){
                break;
            }
        }
        char c = 'a';
        c+= i;
        return c;
    }
};