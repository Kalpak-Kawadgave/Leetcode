class Solution {
public:
    bool check(vector<int>& nums) {
        int size = nums.size();
        int index = -1;
        for (int i = 0; i < size-1; i++){
            if  (nums[i]>nums[i+1]){
                index = i+1;
                break;
            }
        }
        if(index==-1){
            return true;
        }
        for(int i = 0; i < size-1; i++){
            if(nums[(i+index)%size]>nums[(i+index+1)%size]){
                return false;
            }
        }
        return true;
    }
};