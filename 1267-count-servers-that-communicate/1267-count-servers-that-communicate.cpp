class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int count = 0;
        size_t m = grid.size();
        size_t n = grid[1].size();
        vector<pair<int,int>> server;
        vector<int> r(m,0);
        vector<int> c(n,0);
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j]==1){
                    r[i]++;
                    c[j]++;
                    server.push_back(make_pair(i, j));
                }
            }
        }
        for(pair<int,int> a: server){
            if((r[a.first] == 1)&&(c[a.second]==1)){
               count++; 
            }
        }
        return ((server.size())-count);
    }
};