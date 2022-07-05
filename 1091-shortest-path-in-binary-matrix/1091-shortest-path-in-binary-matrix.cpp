void BFS(int x, int y, const size_t &size, const vector<vector<int>>& grid, vector<vector<int>> &visited, queue<vector<int>> &q, int &ans) {
    if (x == size - 1 && y == size - 1) {
        ans = visited[x][y];
    }
    else {
        for (int i = -1; i < 2; ++i) {
            for (int j = -1; j < 2; ++j) {
                if (x + i >= 0 && x + i < size && y + j >= 0 && y + j < size && grid[x + i][y + j] == 0) {
                    if (visited[x + i][y + j] == -1) {
                        q.push({ x + i,y + j });
                        visited[x + i][y + j]= visited[x][y]+ 1;
                    }
                }
            }
        }
    }
    q.pop();
}

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        size_t size = grid.size();
        if (grid[0][0] == 1 || grid[size - 1][size - 1] == 1) {
            return -1;
        }
        int ans = -1;
        vector<vector<int>> visited(size, vector<int>(size, -1));
        queue<vector<int>> q;
        visited[0][0] = 1;
        q.push({ 0, 0 });
        while (!q.empty() && ans == -1) {
            int x = q.front()[0];
            int y = q.front()[1];
            BFS(x,y,size, grid, visited, q, ans);
        }
        return ans;
    }
};