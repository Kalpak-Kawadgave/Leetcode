class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        size_t size = cost.size();
        vector <int> dp(size);
        dp[size - 1] = cost[size - 1];
        dp[size - 2] = cost[size - 2];
        for(int i = size - 3; i >= 0; i--){
            dp[i] = min(cost[i] + dp[i+1], cost[i] + dp[i+2]);
        }
        return min(dp[0],dp[1]);
    }
};