class Solution {
  private:
    bool isPossible(int node, int v, int m, vector<int> adj[], vector<int> &colors, int col){
        for(int adjNode : adj[node]){
            if(colors[adjNode] == col){
                return false;
            }
        }
        return true;
    }
    bool canColor(int node, int v, int m, vector<int> adj[], vector<int>&colors){
        
        if(node == v) return true;
        
        for(int col = 1; col<=m; col++){
            if(isPossible(node, v, m, adj, colors, col)){
                colors[node] = col;
                if(canColor(node+1, v, m, adj, colors)){
                    return true;
                }
                colors[node] = 0;
            }
        }
        
        return false;
        
    }
  public:
    bool graphColoring(int v, vector<vector<int>> &edges, int m) {
        vector<int>adj[v];
        vector<int>colors(v, 0);
        
        for(auto &it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        return canColor(0, v, m, adj, colors);
    }
};