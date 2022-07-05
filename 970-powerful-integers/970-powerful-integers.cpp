class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        set<int> ans{};
        int temp;
        int lim_i;
        int lim_j;
        if (bound==0||bound==1){
        vector<int> b{};
            return b;
        }
        if(x!=1){
            lim_i = ceil(log(bound)/log(x));
        }
        else{
            lim_i = 0;
        }        
        if(y!=1){
            lim_j = ceil(log(bound)/log(y));
        }
        else{
            lim_j = 0;
        }
        for(int i = 0; i <= lim_i; ++i){
            for(int j = 0; j <= lim_j; ++j){
                temp = (pow(x,i)+pow(y,j));
                if(bound >= temp){
                    ans.insert(temp);
                }
            }
        }
        vector<int> a(ans.begin(),ans.end());
        return a;
    }
};