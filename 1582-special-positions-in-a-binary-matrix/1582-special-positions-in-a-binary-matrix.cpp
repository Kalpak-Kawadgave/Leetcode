class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int row_count = mat.size();
        int col_count = mat[1].size();
        vector<int> rows(row_count, 0);
        vector<int> cols(col_count, 0);
        for(int i = 0; i < row_count; ++i){
            for(int j = 0; j < col_count; ++j){
                if(mat[i][j]==1){
                    ++rows[i];
                    ++cols[j];
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < row_count; ++i){
            for(int j = 0; j < col_count; ++j){
                if(mat[i][j]==1&&rows[i]==1&&cols[j]==1){
                    ++ans;
                }
            }
        }
        return ans;
    }
};