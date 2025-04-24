class Solution {
public:
    bool canJump(vector<int>& nums) {
        size_t s = nums.size();
        vector<bool> reachable(s, false);
        reachable[0] = true;

        for (size_t i = 0; i < s; ++i) {
            if (!reachable[i]) continue;
            for (size_t j = 1; j <= nums[i] && i + j < s; ++j) {
                reachable[i + j] = true;
            }
        }

        return reachable[s - 1];
    }
};