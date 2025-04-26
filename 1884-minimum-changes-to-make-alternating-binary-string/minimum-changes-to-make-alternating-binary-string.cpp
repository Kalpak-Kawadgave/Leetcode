class Solution {
public:
    int minOperations(string s) {
        int a = 0;
        int b = 0;
        for (size_t i = 0; i < s.size(); ++i){
            if(i%2==0){
                if(s[i] == '0'){
                    ++a;
                }
                else{
                    ++b;
                }
            }
            else{
                if(s[i] == '0'){
                    ++b;
                }
                else{
                    ++a;
                }
            }
        }
        return min(a,b);
    }
};