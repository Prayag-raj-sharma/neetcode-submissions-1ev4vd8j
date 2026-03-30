class Solution {
private:
    void dfs(int row, int col, int n, int m, vector<vector<char>>& grid,
             vector<vector<int>>& visited) {
        visited[row][col] = 1;
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, -1, 0, 1};

        for(int i = 0; i < 4; i++) {
                int nRow = row + delRow[i];
                int nCol = col + delCol[i];

                if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m
                   && grid[nRow][nCol] == '1' 
                   && !visited[nRow][nCol] ) {
                    dfs(nRow, nCol, n, m, grid, visited);
                }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));
        int count = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!visited[i][j] && grid[i][j] == '1') {
                    dfs(i, j, n, m, grid, visited);
                    count++;
                } 
            }
        }
        return count;
    }
};
