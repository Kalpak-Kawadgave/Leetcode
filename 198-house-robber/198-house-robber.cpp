class Solution {
public:
    int rob(vector<int>& nums) {
        size_t size = nums.size();
        if(size == 1) return nums[0];
        if(size == 2) return max(nums[0],nums[1]);
        vector <int> dp(size);
        dp[size-1] = nums[size - 1];
        dp[size-2] = nums[size - 2];
        dp[size-3] = dp[size-1] + nums[size - 3];
        int m = max(dp[size-1], dp[size-2]);
        int buff = dp[size - 3];
        for(int i = size - 4; i >=0; --i){
            dp[i] = nums[i]+m;
            m = max(m, buff);
            buff = dp[i];
        }
        return max(dp[0],dp[1]);
    }
};