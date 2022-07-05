class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        size_t size = nums.size();
        if(size==1){
            if(nums[0]!=1){
                return 1;
            }
            return 2;
        }
        if(nums[size-1]<0)return 1;
        bool flag = true;
        for(int i = 0; i < size; ++i){
            if(i==size-1){
                nums.push_back(nums[size-1]+2);
            }
            if(nums[i]<=0){
                continue;
            }
            if(flag==true){
                flag = false;
                if(nums[i]!=1)return 1;
            }
            if(nums[i+1]-nums[i]>1){
                return nums[i]+1;
            }
        }
        return -1;
    }
};