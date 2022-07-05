class Solution {
public:
    int tribonacci(int n) {
        int temp;
        vector<int> trib{0,1,1};
        for(int i = 3; i <= n; i++){
            temp = trib[i-1]+trib[i-2]+trib[i-3];
            trib.push_back(temp);
        }
        return trib[n];
    }
};