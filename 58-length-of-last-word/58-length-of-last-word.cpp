class Solution {
public:
    int lengthOfLastWord(string s) {
        int size = s.size();
        int count = 0;
        for (int i = size-1; i >=0 ; i--){
            if(count!=0&&s[i]==' '){
                return count;
            }
            if(isalpha(s[i])){
                count++;
            }
        }
        return count;
    }
};