class Solution {
public:
    bool canJump(vector<int>& nums) {
        size_t s = nums.size();
        vector<bool> ans(s, false);
        ans[0] = true;
        for (size_t i = 0; i < s-1; ++i) {
            if (nums[i] > s - i && ans[i] == true) {
                return true;
            }
            else if (ans[i] == true) {
                for (size_t j = 0; j <= nums[i]; ++j) {
                    if (j+i < s && !(nums[j+i]==0 && j+i<s-1) && ans[j + i] == false && ans[i]==true){
                        ans[j + i] = ans[i];
                    }
                }
            }
        }
        return ans[s - 1];
    }
};