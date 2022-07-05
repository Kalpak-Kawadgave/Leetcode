class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        int ans = 0;
        int size = nums.size();
        if (size<4){
            return ans;
        }
        for(int i=0; i<size-3;i++){
            for(int j=i+1; j<size-2;j++){
                for(int k=j+1; k<size-1;k++){
                    for(int l=k+1; l<size;l++){
                        if(nums[i]+nums[j]+nums[k]==nums[l]){
                            ans++;                            
                        }
                    }
                }
            }
        }
        return ans;
    }
};