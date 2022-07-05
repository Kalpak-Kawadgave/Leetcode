class Solution {
public:
    int climbStairs(int n) {
        int temp;
        vector<int> stairs{0,1,2,3};
        for(int i = 4; i < 46; i++){
            temp = stairs[i-1]+stairs[i-2];
            stairs.push_back(temp);
        }
        return stairs[n];
    }
};