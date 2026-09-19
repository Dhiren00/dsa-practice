class Solution {
public:
    bool dfs(vector<vector<char>>& board, const string& word, int i, int r, int c) {
        if (i == (int)word.size()) return true;            // matched every character
        if (r < 0 || c < 0 || r >= (int)board.size() || c >= (int)board[0].size())
            return false;                                  // out of bounds
        if (board[r][c] != word[i]) return false;          // mismatch (also catches visited '#')

        char saved = board[r][c];
        board[r][c] = '#';                                 // mark visited

        bool found = dfs(board, word, i + 1, r + 1, c) ||
                     dfs(board, word, i + 1, r - 1, c) ||
                     dfs(board, word, i + 1, r, c + 1) ||
                     dfs(board, word, i + 1, r, c - 1);

        board[r][c] = saved;                               // backtrack
        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        for (int r = 0; r < (int)board.size(); r++)
            for (int c = 0; c < (int)board[0].size(); c++)
                if (dfs(board, word, 0, r, c)) return true;
        return false;
    }
};