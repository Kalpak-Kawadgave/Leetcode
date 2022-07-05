class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        size_t size1 = matrix.size();
        size_t size2 = matrix[0].size();
        vector<vector<int>> visited(size1, vector<int>(size2,0));
        vector<int> spiral;
        int i = 0;
        int j = 0;
        int count = 0;
        int limit = size1*size2;
        if(limit == 1){
            return matrix[0];
        }
        while (count < limit){
            for (; j < size2 && visited[i][j] == 0; ++j){
                spiral.push_back(matrix[i][j]);
                visited[i][j] =  1;
                ++count;
                cout<<matrix[i][j];
            }
            --j;
            ++i;
            for (; i < size1 && visited[i][j] == 0; ++i){
                spiral.push_back(matrix[i][j]);
                visited[i][j] =  1;
                ++count;
                cout<<matrix[i][j];
            }
            --i;--j;
            for (; j >= 0 && visited[i][j] == 0; --j){
                spiral.push_back(matrix[i][j]);
                visited[i][j] =  1;
                ++count;
                cout<<matrix[i][j];
            }
            ++j;--i;
            for (; i >= 0 && visited[i][j] == 0; --i){
                spiral.push_back(matrix[i][j]);
                visited[i][j] =  1;
                cout<<matrix[i][j];
                ++count;
            }
            ++i;++j;
        }
        
        return spiral;
    }
};