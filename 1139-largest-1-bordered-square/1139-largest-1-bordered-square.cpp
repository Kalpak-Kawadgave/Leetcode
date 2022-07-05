class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        size_t size1 = grid.size();
        size_t size2 = grid[0].size();
        vector<vector<int>> right(size1, vector<int>(size2, 0));
        vector<vector<int>> down(size1, vector<int>(size2, 0));
        int count ;
        for (int i = 0; i < size1; ++i) {
        count = 0;
            for (int j = size2 - 1; j >= 0; --j) {
                if (grid[i][j] == 1) {
                    ++count;
                }
                else {
                    count = 0;
                }
                right[i][j] = count;
            }
        }
        for (int i = 0; i < size2; ++i) {
        count = 0;
            for (int j = size1 - 1; j >= 0; --j) {
                if (grid[j][i] == 1) {
                    ++count;
                }
                else {
                    count = 0;
                }
                down[j][i] = count;
            }
        }
        count = 0;
        for (int i = 0; i < size1; ++i){
            for (int j = 0; j < size2; ++j) {
                int temp = min(right[i][j], down[i][j]);
                for (int k = temp; k > 0; --k) {
                    if (right[i + k - 1][j] >= k && down[i][j + k - 1]>=k&& k > count) {
                        count = k;
                        break;
                    }
                    if (k <= count) {
                        break;
                    }
                }
            }
        }
        return count*count;
    }
};
