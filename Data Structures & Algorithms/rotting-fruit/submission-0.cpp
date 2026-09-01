class Solution {
private:
    vector<int> delRow = {-1, 0, 1, 0};
    vector<int> delCol = {0, 1, 0, -1};

    void bfs(int row, int col, queue<pair<int, int>>& q, vector<vector<int>>& dummy, int& oranges, int& time) {
        while(!q.empty()) {
            int k = q.size();

            oranges += k;


            while(k--) {
                auto [r, c] = q.front();
                q.pop();

                for(int i = 0; i < 4; i++) {
                    int nr = r + delRow[i];
                    int nc = c + delCol[i];

                    if(nr >= 0 && nr < row && nc >= 0 && nc < col
                       && dummy[nr][nc] == 1) {
                        dummy[nr][nc] = 2;
                        q.push({nr, nc});
                    }
                }
            }
            if(!q.empty()) time++;
        }
    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dummy = grid;

        int time = 0;
        queue<pair<int, int>> q;
        int totalOranges = 0;
        int currentOranges = 0;

        for(int r = 0; r < n; r++) {
            for(int c = 0; c < m; c++) {
                if(grid[r][c] != 0) totalOranges++;
                if(dummy[r][c] == 2) {
                    q.push({r, c});
                }
            }
        }
        bfs(n, m, q, dummy, currentOranges, time);

        if(totalOranges == currentOranges) return time;
        return -1;
    }
};

