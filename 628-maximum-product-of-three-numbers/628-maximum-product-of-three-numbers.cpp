class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        size_t size = nums.size();
        sort(nums.begin(), nums.end());
        int m = nums[0]*nums[1]*nums[size-1];
        int n = nums[size-1]*nums[size-2]*nums[size-3];
        return max(m,n);
    }
};