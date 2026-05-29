class Solution {
public:
    void backtrack(vector<vector<char>>& board, string_view word, int i, int j, vector<vector<bool>>& visited, bool& found) {
        if (word.size() == 0) {
            found = true;
            return;
        }
        int m = board.size();
        int n = board[0].size();
        if (i >=m || j >= n || i < 0 || j < 0) return;//out of bound
        if (visited[i][j]) return;
        if (found) return;
        if(word[0] != board[i][j]) return;
        visited[i][j] = true;
        std::string_view sv = word.substr(1);
        backtrack(board, sv, i-1, j,visited, found);
        backtrack(board, sv, i+1, j, visited, found);
        backtrack(board, sv, i, j-1, visited, found);
        backtrack(board, sv, i, j+1, visited, found);
        visited[i][j] = false;
    }

    bool exist(vector<vector<char>>& board, string word) {

        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> visited(m, std::vector<bool>(n, false));
        bool found = false;
        for (int i = 0; i < m; i++) {
            for(int j = 0; j< n; j++) {
                backtrack(board, word, i, j, visited, found);
                if (found) break;
            }
        }

        return found;

    }
};
