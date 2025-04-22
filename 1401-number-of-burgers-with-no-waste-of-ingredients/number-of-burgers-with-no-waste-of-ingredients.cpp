class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        vector<int> ans;
        if(tomatoSlices%2==0){
            int temp1 = tomatoSlices/2 - cheeseSlices;
            int temp2 = cheeseSlices - temp1;
            if(temp1>=0 && temp2>=0 ){
                ans.emplace_back(temp1); 
                ans.emplace_back(temp2); 
            }
        }
        return ans; 
    }
};