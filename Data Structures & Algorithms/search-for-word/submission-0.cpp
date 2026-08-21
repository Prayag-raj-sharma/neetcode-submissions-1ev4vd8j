class Solution {
private:
    bool solve(int row, int col, vector<vector<char>>& board, string word, int k) {
        if(k == word.length()) {
            return true;
        }

        if(row < 0 || col < 0 || row >= board.size() 
           || col >= board[0].size() 
           || word[k] != board[row][col]) {
            return false;
        }

        bool ans = false;

        char x = board[row][col];
        board[row][col] = ' ';

        ans |= solve(row + 1, col, board, word, k + 1);
        ans |= solve(row - 1, col, board, word, k + 1);
        ans |= solve(row, col + 1, board, word, k + 1);
        ans |= solve(row, col - 1, board, word, k + 1);

        board[row][col] = x;
        return ans;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(solve(i, j, board, word, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
};
