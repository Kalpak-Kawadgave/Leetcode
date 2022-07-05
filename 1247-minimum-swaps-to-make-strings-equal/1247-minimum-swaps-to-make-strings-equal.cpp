class Solution {
public:
    int minimumSwap(string s1, string s2) {
        if(s1 == s2) return 0;
        size_t size = s1.size();
        int count1 = 0;
        int count2 = 0;
        for(int i = 0; i < size; ++i){
            if(s1[i]=='x'&&s2[i]=='y'){
                ++count1;
            }
            else if(s1[i]=='y'&&s2[i]=='x'){
                ++count2;
            }
        }
        if((count1+count2)%2==0){
            return ((count1/2)+(count2/2)+2*(count1%2));
        }
        return -1;
    }
};