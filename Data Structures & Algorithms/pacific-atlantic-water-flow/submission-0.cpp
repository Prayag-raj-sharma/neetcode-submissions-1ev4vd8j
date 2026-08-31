class Solution {
private:
    vector<int> delRow = {-1, 0, 1, 0};
    vector<int> delCol = {0, 1, 0, -1};
    void bfs(vector<vector<int>>& heights, vector<vector<bool>>& visited, queue<pair<int, int>>& q) {
        int rows = heights.size();
        int cols = heights[0].size();

        while(!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for(int i = 0; i < 4; i++) {
                int nr = r + delRow[i];
                int nc = c + delCol[i];

                if(nr < 0 || nr >= rows || nc < 0 || nc >= cols) {
                    continue;
                }

                if(visited[nr][nc]) continue;

                if(heights[nr][nc] < heights[r][c]) {
                    continue;

                }

                visited[nr][nc] = true;
                q.push({nr, nc});
            }
            
        }

    }
    
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<bool>> pacific(n, vector<bool>(m, false));

        vector<vector<bool>> atlantic(n, vector<bool>(m, false));

        queue<pair<int, int>> qP;
        queue<pair<int, int>> qA;

        // Pacific
        for(int r = 0; r < n; r++) {
            if(!pacific[r][0]) {
                pacific[r][0] = true;
                qP.push({r, 0});
            }
        }

        for(int c = 0; c < m; c++) {
            if(!pacific[0][c]) {
                pacific[0][c] = true;
                qP.push({0, c});
            }
        }

        // Atlantic
        for(int r = 0; r < n; r++) {
            if(!atlantic[r][m - 1]) {
                atlantic[r][m - 1] = true;
                qA.push({r, m - 1});
            }
        }

        for(int c = 0; c < m; c++) {
            if(!atlantic[n - 1][c]) {
                atlantic[n - 1][c] = true;
                qA.push({n - 1, c});
            }
        }

        bfs(heights, pacific, qP);
        bfs(heights, atlantic, qA);

        vector<vector<int>> result;

        for (int r = 0; r < n; r++) {
            for (int c = 0; c < m; c++) {
                if (pacific[r][c] && atlantic[r][c]) {
                    result.push_back({r, c});
                }
            }
        }

        return result;
    }
};
