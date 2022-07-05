class Solution {
public:
	vector<int> findBall(vector<vector<int>>& grid) {
		size_t column = grid.size();
		size_t row = grid[0].size();
		vector<int> ans;
		vector<vector<int>> pgrid(column, vector<int>(row + 2, 1));
		vector<vector<int>> dp(column, vector<int>(row + 2, 0));
		for (int i = 0; i < column; ++i) {
			for (int j = 0; j < row; ++j) {
				pgrid[i][j + 1] = grid[i][j];
			}
		}
		for (int i = 0; i < column; ++i) {
			pgrid[i][row + 1] = -1;
		}
		for (int i = 1; i <= row; ++i) {
			ans.push_back(this->rec(0, i, pgrid, dp));
		}
		return ans;
	}

	int rec(int x, int y, vector<vector<int>>& grid, vector<vector<int>>& dp) {
		if (x >= grid.size()) {
			return y - 1;
		}
		else if ((grid[x][y] == 1 && grid[x][y + 1] == -1) || (grid[x][y] == -1 && grid[x][y - 1] == 1)) {
			dp[x][y] = -1;
			return -1;
		}
		else if (grid[x][y] == 1 && grid[x][y + 1] == 1) {
			if (dp[x][y] == 0) {
				dp[x][y] = rec(x + 1, y + 1, grid, dp);
				return dp[x][y];
			}
			else {
				return dp[x][y];
			}
		}
		else if (grid[x][y] == -1 && grid[x][y - 1] == -1) {
			if (dp[x][y] == 0) {
				dp[x][y] = rec(x + 1, y - 1, grid, dp);
				return dp[x][y];
			}
			else {
				return dp[x][y];
			}
		}
		return 0;
	}
};