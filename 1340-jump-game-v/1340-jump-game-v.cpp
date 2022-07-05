class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        int size = arr.size();
        vector<pair<int, int>> pos;
        for (int i = 0; i < size; ++i) {
            pos.push_back(make_pair(arr[i], i));
        }
        sort(pos.begin(), pos.end());
        vector<int> dp(size,0);
        int prev, next;
        for(int i = 0; i < size; i++){
            prev=min(d,pos[i].second);
            next=min(d+1,size-pos[i].second);
            for(int j = 1; j <= prev; j++){
                if(arr[pos[i].second-j]>=arr[pos[i].second]){
                    break;
                }
                dp[pos[i].second]=max(dp[pos[i].second-j]+1,dp[pos[i].second]);
            }
            for(int j = 1; j < next; j++){
                if(arr[pos[i].second+j]>=arr[pos[i].second]){
                    break;
                }
                dp[pos[i].second]=max(dp[pos[i].second+j]+1,dp[pos[i].second]);
            }
        }
        int max = 0;
        for(int i = 0; i < size; i++){
            if(max < dp[i]){
                max = dp[i]; 
            } 
        }
        return max+1;
    }
};