class Solution {

    void solve(int i, int j, vector<vector<char>>& grid, 
               vector<vector<int>>& vis, int n, int m) {

        vis[i][j] = 1;

        //up
        if(i-1 >= 0 && grid[i-1][j] == '1' && vis[i-1][j] == 0) {
            solve(i-1, j, grid, vis, n, m);
        } 

        //down
        if(i+1 <= n-1 && grid[i+1][j] == '1' && vis[i+1][j] == 0) {
            solve(i+1, j, grid, vis, n, m);
        } 

        //right
        if(j+1 <= m-1 && grid[i][j+1] == '1' && vis[i][j+1] == 0) {
            solve(i, j+1, grid, vis, n, m);
        } 

        //left
        if(j-1 >= 0 && grid[i][j-1] == '1' && vis[i][j-1] == 0) {
            solve(i, j-1, grid, vis, n, m);
        }  

        // //noretheast
        // if(i-1 >= 0 && j+1 <= m-1 && grid[i-1][j+1] == '1' && vis[i-1][j+1] == 0) {
        //     solve(i-1, j+1, grid, vis, n, m);
        // }  

        // //northwest
        // if(i-1 >= 0 && j-1 >= 0 && grid[i-1][j-1] == '1' && vis[i-1][j-1] == 0) {
        //     solve(i-1, j-1, grid, vis, n, m);
        // } 

        // //southeast
        // if(i+1 <= n-1 && j+1 <= m-1 && grid[i+1][j+1] == '1' && vis[i+1][j+1] == 0) {
        //     solve(i+1, j+1, grid, vis, n, m);
        // }  

        // //southwest
        // if(i+1 <= n-1  && j-1 >= 0 && grid[i+1][j-1] == '1' && vis[i+1][j-1] == 0) {
        //     solve(i+1, j-1, grid, vis, n, m);
        // }   
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0; 
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == '1' && vis[i][j] == 0) {

                    count++;
                    solve(i, j, grid, vis, n, m);
                }
            }
        }

        return count;
    }
};