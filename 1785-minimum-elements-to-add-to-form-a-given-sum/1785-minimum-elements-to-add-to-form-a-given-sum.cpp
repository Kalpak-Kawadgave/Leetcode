class Solution {
public:
        int minElements(vector<int>& A, int limit, int goal) {
        long sum = accumulate(A.begin(), A.end(), 0L),  diff = abs(goal - sum);
        return (diff + limit - 1) / limit;
    }
    // int minElements(vector<int>& nums, int limit, int goal) {
    //     long long sum = 0;
    //     for(auto a:  nums){
    //         sum+=a;
    //     }
    //     double diff = abs(sum - goal);
    //     auto ans = ceil(diff/limit);
    //     return ans;
    // }
};