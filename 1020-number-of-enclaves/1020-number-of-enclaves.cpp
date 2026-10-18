class Solution {

    void dfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>> &vis, int n, int m) {
        vis[row][col] = 1;

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        for(int i = 0; i < 4; i++) {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol]
                && grid[nrow][ncol] == 1) {
                    vis[nrow][ncol] = 1;
                    dfs(nrow, ncol, grid, vis, n, m);
            }
         }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>> vis(n, vector<int> (m, 0));

        // Top row
        for(int j = 0; j < m; j++) {
            // matrix[0][j]
            
            if(grid[0][j] == 1) {
                dfs(0, j, grid, vis, n, m);
            }
        }

        // Right column
        for(int i = 1; i < n; i++) {
            // matrix[i][m-1]
            
            if(grid[i][m-1] == 1) {
                dfs(i, m-1, grid, vis, n, m);
            }
        }

        // Bottom row
        for(int j = m-2; j >= 0; j--) {
            // matrix[n-1][j]
            
            if(grid[n-1][j] == 1) {
                dfs(n-1, j, grid, vis, n, m);
            }
        }

        // Left column
        for(int i = n-2; i > 0; i--) {
            // matrix[i][0]
            
            if(grid[i][0] == 1) {
                dfs(i, 0, grid, vis, n, m);
            }
        }

        int count = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1 && !vis[i][j]) {
                    count++;
                }
            }
        }

        return count;
    }
};