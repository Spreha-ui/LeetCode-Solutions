class Solution {

    void solve(int node, vector<vector<int>>& adj, 
               vector<int> &vis) {
        
        
        vis[node] = 1;

        vector<int> &vec = adj[node];
        for(auto i: vec) {
            if(vis[i] != 1) {
                solve(i, adj, vis);
            }
        }
        
        
        
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int n = isConnected.size();
        vector<vector<int>> adj(n);

        //making adjecency list
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(isConnected[i][j] == 1) {
                    adj[i].push_back(j);
                }
            }
        }

        vector<int> vis(n, 0);
        int count = 0;

        for(int i = 0; i < n; i++) {

            if(vis[i] == 0) {
                count++;
                solve(i, adj, vis);
            }
        }

        return count;
    }
};