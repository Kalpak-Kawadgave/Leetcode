class Graph 
{
public:
    unordered_map<int, bool> visited;
    unordered_map<int, list<int>> adj;
    set <vector<int>> marker;
    void addEdge(vector<int> edge);
    bool DFS(int v, const vector<bool>& hasApple);
    int Count()
    {
        return marker.size();
    }
};

void Graph::addEdge(vector<int> edge)
{
    adj[edge[0]].push_back(edge[1]);
    adj[edge[1]].push_back(edge[0]);
}
  
bool Graph::DFS(int v, const vector<bool>& hasApple)
{
    bool hasA = hasApple[v];
    bool check;
    visited[v] = true;
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i){
        if (!visited[*i]){
            check = DFS(*i, hasApple);
            if(check == true){
                marker.insert({v,*i});
            }
            hasA = hasA || check;
        }
    }
    return hasA;
    
}
class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        Graph g;
        for(auto edge: edges){
            g.addEdge(edge);
        }
        g.DFS(0, hasApple);  
        return (g.Count())*2;
    }
};
