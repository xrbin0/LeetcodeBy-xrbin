#include "0000.h"

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int row = board.size();
        if(row == 0) return;
        int col = board[0].size();
        if(col <= 2 || row <= 2) return;

        for(int i = 0;i < col;i++){
            if(board[0][i] == 'O') board[0][i] = 'V';
            if(board[row - 1][i] == 'O') board[row - 1][i] = 'V';
        }
        for(int i = 0;i < row;i++){
            if(board[i][0] == 'O') board[i][0] = 'V';
            if(board[i][col - 1] == 'O') board[i][col - 1] = 'V';
        }

        for(int i = 1;i < row - 1;i++){
            for(int j = 1;j < col - 1;j++){
                if(board[i][j] == 'O'){
                    vector <int> x;
                    vector <int> y;
                    x.push_back(i); y.push_back(j);
                    board[i][j] = 'Y';
                    All_adjacent_0(x, y, board);
                    if(Adjacent_border(x, y, board)){
                        for(int k = 0;k < x.size();k++){
                            board[x[k]][y[k]] = 'V';
                        }
                    }
                    else{
                        for(int k = 0;k < x.size();k++){
                            board[x[k]][y[k]] = 'X';
                        }
                    }
                    x.clear(); y.clear();
                }
            }
        }

        for(int i = 0;i < row;i++){
            for(int j = 0;j < col;j++){
                if(board[i][j] == 'V') board[i][j] = 'O';
            }
        }

        return;
    }

    void All_adjacent_0(vector <int>& x, vector <int>& y, vector<vector<char>>& board){
        int cur_x = x[x.size() - 1];
        int cur_y = y[y.size() - 1];
        // 漏了两个方向，以为不需要考虑。 
        // 等于Y是后来加上的，这个有点意思。
        if(board[cur_x + 1][cur_y] == 'O'){
            board[cur_x + 1][cur_y] = 'Y';
            x.push_back(cur_x + 1);
            y.push_back(cur_y);
            All_adjacent_0(x, y, board);
        }
        if(board[cur_x - 1][cur_y] == 'O'){
            board[cur_x - 1][cur_y] = 'Y';
            x.push_back(cur_x - 1);
            y.push_back(cur_y);
            All_adjacent_0(x, y, board);
        }
        if(board[cur_x][cur_y + 1] == 'O'){
            board[cur_x][cur_y + 1] = 'Y';
            x.push_back(cur_x);
            y.push_back(cur_y + 1);
            All_adjacent_0(x, y, board);
        }
        if(board[cur_x][cur_y - 1] == 'O'){
            board[cur_x][cur_y - 1] = 'Y'; 
            x.push_back(cur_x);
            y.push_back(cur_y - 1);
            All_adjacent_0(x, y, board);
        }
    }

    bool Adjacent_border(vector <int>& x, vector <int>& y, vector<vector<char>>& board){
        for(int k = 0;k < x.size();k++){
            if(board[x[k] - 1][y[k]] == 'V') return true;
            if(board[x[k]][y[k] - 1] == 'V') return true;
            if(board[x[k] + 1][y[k]] == 'V') return true;
            if(board[x[k]][y[k] + 1] == 'V') return true;
        }
        return false;
    }
};


