class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        size_t size = nums.size();
        if (size == 1) return nums;
        
        vector<int> ans;
        
        int sum = 0;
        for(int i = 0; i < size; ++i){
            sum+=nums[i];
        }
        int half = ceil((float)sum/2);
        
        sort(nums.begin(), nums.end(),greater<int>());
        
        int i = 0;
        while(sum>=half){
            cout<<sum<<" "<<half<<"\n";
            ans.push_back(nums[i]);
            sum-=nums[i];
            ++i;
        }
        
        sort(ans.begin(), ans.end(), greater<int>());
        return ans;
    }
};