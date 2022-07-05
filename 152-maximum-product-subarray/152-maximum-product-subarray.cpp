class Solution {
public:
    int maxProduct(vector<int>& nums) {
        size_t size = nums.size();
        int ans = INT_MIN;
        int pref_product = 1;
        int suff_product = 1;
        for (int i = 0; i < size; ++i){
            pref_product*=nums[i];
            ans = max(ans, pref_product);
            if(pref_product == 0) pref_product = 1;
            suff_product*=nums[size - 1 - i];
            ans = max(ans, suff_product);
            if(suff_product == 0) suff_product = 1;
        }
        return ans;
    }
};