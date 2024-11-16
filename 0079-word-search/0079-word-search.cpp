class Solution {
public:

    bool backtrack(vector<vector<char>>& board, string& word, int index, int r, int c, vector<pair<int, int>>& path) {

        if(index == word.size()){
            return true;
        }

        if(r<0 || c<0 || r>=board.size() || c >= board[0].size() || board[r][c] != word[index]){
            return false;
        }


        char temp = board[r][c];
        board[r][c] = '*';
        path.push_back({r,c});

        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (auto dir : directions) {
            int new_r = r + dir.first;
            int new_c = c + dir.second;
            if (backtrack(board, word, index + 1, new_r, new_c, path)) {
                return true;
            }
        }

        board[r][c] = temp;
        path.pop_back();
        return false;


    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        int i,j;
        vector<pair<int, int>> path;

         for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {  // Start searching from this cell
                    if (backtrack(board, word, 0, i, j, path)) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};