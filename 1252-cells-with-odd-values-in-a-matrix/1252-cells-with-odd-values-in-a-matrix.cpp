class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        vector<vector<int>> mat(m, vector<int>(n,0));
        int ans = 0;
        for(auto a: indices){
            for(int i = 0; i < n; ++i){
                mat[a[0]][i]++;
            }
            for(int i = 0; i < m; ++i){
                mat[i][a[1]]++;
            }
        } 
        for(auto a:mat){
            for(int b: a){
                if(b%2==1){
                    ans++;
                }
            }
        }
        return ans;
    }
};