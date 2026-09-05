class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();

        priority_queue<pair<int, pair<int, int>>, 
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>> >pq;

        vector<vector<int>> minTime(n, vector<int>(n, 1e9));

        vector<pair<int, int>> directions = {
            {0, 1}, {0, -1}, {1, 0}, {-1, 0}
        }; // Imp..

        minTime[0][0] = grid[0][0];

        pq.push({grid[0][0], {0, 0}});

        while(!pq.empty()) {
            auto [time, pos] = pq.top();
            pq.pop();

            auto [r, c] = pos;

            if(r == n - 1 && c == n - 1) return time;

            if(time > minTime[r][c]) continue;

            for(auto [dr, dc]: directions) {
                int nr = r + dr;
                int nc = c + dc;

                if(nr < 0 || nr >= n || nc < 0 || nc >= n) continue;

                int nextTime = max(time, grid[nr][nc]);

                if(nextTime < minTime[nr][nc]) {
                    minTime[nr][nc] = nextTime;
                    pq.push({nextTime, {nr, nc}});
                }
            }
        } 
        return -1;
    }
};
