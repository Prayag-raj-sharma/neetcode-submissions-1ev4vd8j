class Solution {
private:
    bool isSafe(int row, int col, vector<string>& board) {
        int r = row, c = col;

        // check top
        while(r >= 0) {
            if(board[r][c] == 'Q') return false;
            r--;
        }

        r = row, c = col;

        // check diagonal right
        while(r >= 0 && c >= 0) {
            if(board[r][c] == 'Q') return false;
            r--;
            c--;
        }

        r = row, c = col;

        // check top
        while(r >= 0 && c < board[0].size()) {
            if(board[r][c] == 'Q') return false;
            r--;
            c++;
        }
        return true;
    }
    void solve(int row, vector<string>& board, vector<vector<string>>& ans) {
        if(row == board.size()) {
            ans.push_back(board);
            return;
        }

        for(int col = 0; col < board[0].size(); col++) {
            if(isSafe(row, col, board)) {
                board[row][col] = 'Q';
                solve(row + 1, board, ans);
                board[row][col] = '.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;

        vector<string> board(n, string(n, '.'));

        solve(0, board, ans);
        return ans;
    }
};
