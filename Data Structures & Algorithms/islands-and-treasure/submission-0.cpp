class Solution {
public:
    vector<int> delRow = {-1, 0, 1, 0};
    vector<int> delCol = {0, 1, 0, -1};
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;

        for(int row = 0; row < n; row++) {
            for(int col = 0; col < m; col++) {
                if(grid[row][col] == 0) {
                    q.push({row, col});
                }
            }
        }
        
        while(!q.empty()) {
            int size = q.size();

            while(size--) {
                auto [r, c] = q.front();
                q.pop();

                for(int i = 0; i < 4; i++) {
                    int newr = r + delRow[i];
                    int newc = c + delCol[i];

                    if(newr < 0 || newr >= n || newc < 0 
                    || newc >= m || grid[newr][newc] != INT_MAX) {
                        continue;
                    }

                    grid[newr][newc] = grid[r][c] + 1;
                    q.push({newr, newc});
                }
            }
        }
    }
};
