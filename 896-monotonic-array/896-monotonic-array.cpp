class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int i = 0;
        int size = nums.size();
        if (size==1){
            return true;
        }
        while(nums[i]==nums[i+1]){
            if(i == size-2){
                break;
            }
            i++;
        }
        if(i==size-1){
            return true;
        }
        if(nums[i]>nums[i+1]){
            for (i;i <size-1;i++){
                if(nums[i]<nums[i+1]){
                    return false;
                }
            }
        }
        else {
            for (i ; i <size-1;i++){
                if(nums[i]>nums[i+1]){
                    return false;
                }
            }
        }
        return true;
    }
};