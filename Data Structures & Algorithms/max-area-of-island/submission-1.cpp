class Solution {
private:
    void dfs(int row, int col, int n, int m, vector<vector<int>>& grid,
             vector<vector<int>>& vis, int& area) {
        vis[row][col] = 1;
        area++;

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        for(int i = 0; i < 4; i++) {
            int nRow = row + delRow[i];
            int nCol = col + delCol[i];

            if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m
               && !vis[nRow][nCol] && grid[nRow][nCol] == 1) {
                dfs(nRow, nCol, n, m, grid, vis, area);
            }
        }

    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int maxArea = 0;
        vector<vector<int>> vis(n + 1, vector<int>(m + 1, 0));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!vis[i][j] && grid[i][j] == 1) {
                    int area = 0;
                    dfs(i, j, n, m, grid, vis, area);
                    maxArea = max(maxArea, area);
                }
            }
        }
        return maxArea;
    }
};
