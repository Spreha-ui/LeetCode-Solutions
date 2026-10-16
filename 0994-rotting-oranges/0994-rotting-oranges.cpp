class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(); // rows
        int m = grid[0].size(); //col

        vector<vector<int>> vis(n, vector<int> (m, 0));

        queue<pair<pair<int, int>, int>> q; //{{r, c}, time}

        int delrow[] = {-1, 0, +1, 0};
        int delcol[] = {0, +1, 0, -1};

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    vis[i][j] = 2;
                }
            }
        } 

        int time = 0;
        while(!q.empty()) {
            auto temp = q.front();
            q.pop();

            int row = temp.first.first;
            int col = temp.first.second;
            int t = temp.second;

            time = max(time, t);

            for(int k = 0; k < 4; k++) {
                int nrow = row + delrow[k];
                int ncol = col + delcol[k];

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m
                    && grid[nrow][ncol] == 1 && vis[nrow][ncol] != 2) {
                        q.push({{nrow, ncol}, t+1});
                        vis[nrow][ncol] = 2;
                }
            }
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1 && vis[i][j] != 2) {
                    return -1;
                }
            }
        }

        return time;
    }
};