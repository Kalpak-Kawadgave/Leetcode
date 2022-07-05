class Solution {
public:
    int maxProduct(vector<int>& nums) {
        size_t size = nums.size();
        sort(nums.begin(), nums.end());
        return (nums[size-1]-1)*(nums[size-2]-1);
    }
};