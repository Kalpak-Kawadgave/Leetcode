class Solution {
public:
    int maxScore(vector<int>& cp, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        size_t size = cp.size();
        int sum = 0;
        for(int i = size-k; i < size; ++i){
            sum+=cp[i];
        }
        int m = sum;
        for(int i = 0 ; i < k; ++i){
            sum+=cp[i];
            sum-=cp[size - k + i];
            m = max(sum,m);
        }
        return m;
    }
};