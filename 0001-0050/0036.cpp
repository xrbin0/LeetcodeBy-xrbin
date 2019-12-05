#include "0000.h"

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0;i < 9;i++){
            int flag[10] = {0,0,0,0,0,0,0,0,0,0};
            for(int j = 0;j < 9;j++){
                if(board[i][j] != '.'){
                    if(flag[board[i][j]-'0'] == 1){
                        return false;
                    }
                    flag[board[i][j]-'0'] = 1;
                }
            }
        }
        for(int j = 0;j < 9;j++){
            int flag[10] = {0,0,0,0,0,0,0,0,0,0};
            for(int i = 0;i < 9;i++){
                if(board[i][j] != '.'){
                    if(flag[board[i][j]-'0'] == 1){
                        return false;
                    }
                    flag[board[i][j]-'0'] = 1;
                }
            }
        }
        for(int k = 0;k < 3;k++){
            int flag[10] = {0,0,0,0,0,0,0,0,0,0};
            for(int i = 3;i < 6;i++){
                for(int j = 0;j < 3;j++){
                    if(board[i][j+3*k] != '.'){
                        if(flag[board[i][j+3*k]-'0'] == 1){
                            return false;
                        }
                        flag[board[i][j+3*k]-'0'] = 1;
                    }
                }
            }
        }
        for(int k = 0;k < 3;k++){
            int flag[10] = {0,0,0,0,0,0,0,0,0,0};
            for(int i = 6;i < 9;i++){
                for(int j = 0;j < 3;j++){
                    if(board[i][j+3*k] != '.'){
                        if(flag[board[i][j+3*k]-'0'] == 1){
                            return false;
                        }
                        flag[board[i][j+3*k]-'0'] = 1;
                    }
                }
            }
        }
        for(int k = 0;k < 3;k++){
            int flag[10] = {0,0,0,0,0,0,0,0,0,0};
            for(int i = 0;i < 3;i++){
                for(int j = 0;j < 3;j++){
                    if(board[i][j+3*k] != '.'){
                        if(flag[board[i][j+3*k]-'0'] == 1){
                            return false;
                        }
                        flag[board[i][j+3*k]-'0'] = 1;
                    }
                }
            }
        }
        return true;
    }
};