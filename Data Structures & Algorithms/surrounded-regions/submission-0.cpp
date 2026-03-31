class Solution {
private:
    void bfs(int r, int c, vector<vector<char>>& board, vector<vector<int>>& visited) {
        int n = board.size();
        int m = board[0].size();

        queue<pair<int, int>> q;
        q.push({r, c});
        visited[r][c] = 1;

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        while(!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for(int i = 0; i < 4; i++) {
                int row = x + delRow[i];
                int col = y + delCol[i];

                if(row >= 0 && row < n && col >= 0 && col < m
                   && !visited[row][col] && board[row][col] == 'O') {
                    visited[row][col] = 1;
                    q.push({row, col});
                }
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> visited(n + 1, vector<int>(m + 1, 0));

        for(int i = 0; i < m; i++) {
            if(board[0][i] == 'O' && !visited[0][i]) {
                bfs(0, i, board, visited);
            }
            if(board[n - 1][i] == 'O' && !visited[n - 1][i]) {
                bfs(n - 1, i, board, visited);
            }
        }

        for(int i = 0; i < n; i++) {
            if(board[i][0] == 'O' && !visited[i][0]) {
                bfs(i, 0, board, visited);
            }
            if(board[i][m - 1] == 'O' && !visited[i][m - 1]) {
                bfs(i, m - 1, board, visited);
            }
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(board[i][j] == 'O' && !visited[i][j]) {
                    board[i][j] = 'X';
                }
            }
        } 
    }
};
