#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <list>
#include <unistd.h>
#include <stack>
#include <stdio.h>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<bool> >rows;
    vector<vector<bool> >cols;
    vector<vector<bool> >diamond;
    vector<vector<int> >pre;
    bool flag; int counss;
    
    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<bool> >to1 (9,vector<bool>(9,0));
        flag = 0;counss = 0;
        rows = to1;cols = to1;diamond = to1;

        for(int i = 0;i < 9;i++){
            for(int j = 0;j < 9;j++){
                // cout<<"win"<<endl;
                vector <int> temp;
                if(board[i][j] != '.'){
                    rows[i][board[i][j] - '0' - 1] = 1;
                    cols[j][board[i][j] - '0' - 1] = 1;
                    int cos = (i / 3) * 3 + (j / 3);
                    diamond[cos][board[i][j] - '0' - 1] = 1;
                    pre.push_back(temp);
                }else{
                    vector<bool> rem(9,0);
                    for(int k = 0;k < 9;k++){
                        if(board[k][j] != '.')
                            rem[board[k][j] - '0' - 1] = 1;
                        if(board[i][k] != '.')
                            rem[board[i][k] - '0' - 1] = 1;
                    }
                    int ro = i / 3 * 3;
                    int co = j / 3 * 3;
                    for(int k = 0;k < 3;k++)
                    for(int s = 0;s < 3;s++){
                        if(board[k+ro][s+co] != '.'){
                            rem[board[k+ro][s+co] - '0' - 1] = 1;
                            // cout<<board[k+ro][s+co]<<" ";
                        }
                    }
                    for(int k = 0;k < 9;k++){
                        if(rem[k] == 0)temp.push_back(k+1);
                    }
                    pre.push_back(temp);
                    counss++;
                    // cout<<i<<" "<<j<<endl;
                    // for(int i = 0;i < temp.size();i++)cout<<temp[i]<<" ";cout<<endl;
                    temp.clear();
                }
            }
            
        }

        // for(int i = 0;i < 9;i++){
        //     for(int j = 0;j < 9;j++){
        //         cout<<rows[i][j]<<" ";
        //     }cout<<endl;
        // }
        // cout<<counss<<endl;
        // cout<<pre.size()<<endl;
        func(0, 0, board);
    }
    // int ss = 0;
    void func(int bi, int bj, vector<vector<char>>& board){
        // ss++;
        // if(ss % 100 == 0)sleep(1);
        // cout<<bi<<" "<<bj<<"   "<<endl;
        // if(counss<15)
            // cout<<counss;
        if(flag) return;
        // for(int i = 0;i < 9;i++){
        //     for(int j = 0;j < 9;j++){
        //         cout<<rows[i][j]<<" ";
        //     }cout<<" ";
        //     for(int j = 0;j < 9;j++){
        //         cout<<cols[i][j]<<" ";
        //     }cout<<" ";
        //     for(int j = 0;j < 9;j++){
        //         cout<<diamond[i][j]<<" ";
        //     }cout<<" ";
        //     cout<<endl;
        // }cout<<endl;
        
        if(bj == 9){
            bj = 0; 
            bi += 1;
        }
        bool flagc = 0;
        for(int i = bi;i < 9;i++){
            for(int j = 0;j < 9;j++){//j = 0, j = bj;
                if(board[i][j] == '.'){
                    for(int k = 0;k < pre[i * 9 + j].size();k++){
                        // cout<<i<<" "<<j<<" ";
                        // if(i == 0 && j == 2)
                        // cout<<pre[i * 9 + j][k]<<endl;
                        // if(i == 0 && j == 3)cout<<pre[i * 9 + j][k]<<" ";
                        int temp = pre[i * 9 + j][k] - 1;
                        if(judge(i, j, temp)){
                            board[i][j] = pre[i * 9 + j][k] + '0';
                            int cos = (i / 3) * 3 + (j / 3);
                            rows[i][board[i][j] - '0' - 1] = 1;
                            cols[j][board[i][j] - '0' - 1] = 1;
                            diamond[cos][board[i][j] - '0' - 1] = 1;

                            counss--;

                            if(counss == 0){
                                flag = 1;
                                return;
                            }
                            func(i, j+1, board);

                            if(flag == 0){
                                rows[i][board[i][j] - '0' - 1] = 0;
                                cols[j][board[i][j] - '0' - 1] = 0;
                                diamond[cos][board[i][j] - '0' - 1] = 0;
                                board[i][j] = '.';
                                counss++;
                            }
                        }
                    }
                    flagc = 1;
                    break;
                }
            }
            if(flagc == 1)break;//less, before.
        }
    }

    bool judge(int i, int j, int numb){
        int cos = (i / 3) * 3 + (j / 3);
        // cout<<rows[i][numb]<<" "<<cols[j][numb]<<" "<<diamond[cos][numb]<<endl;
        if(rows[i][numb] == 1)return false;
        if(cols[j][numb] == 1)return false;
        if(diamond[cos][numb] == 1)return false;
        return true;
    }
};


int main(){
    // for(int i = 0;i < 9;i++){
    //     for(int j = 0;j < 9;j++){
    //         cout<<(i / 3) * 3 + (j / 3)<<" ";
    //     }cout<<endl;
    // }
    vector<vector<char>> board;
    vector<char> a1{'5','3','.','.','7','.','.','.','.'};
    vector<char> a2{'6','.','.','1','9','5','.','.','.'};
    vector<char> a3{'.','9','8','.','.','.','.','6','.'};
    vector<char> a4{'8','.','.','.','6','.','.','.','3'};
    vector<char> a5{'4','.','.','8','.','3','.','.','1'};
    vector<char> a6{'7','.','.','.','2','.','.','.','6'};
    vector<char> a7{'.','6','.','.','.','.','2','8','.'};
    vector<char> a8{'.','.','.','4','1','9','.','.','5'};
    vector<char> a9{'.','.','.','.','8','.','.','7','9'};
    // vector<char> a1{'5','3','4','6','7','8','9','1','2'};
    // vector<char> a2{'6','7','2','1','9','5','3','4','8'};
    // vector<char> a3{'1','9','8','3','4','2','5','6','7'};
    // vector<char> a4{'8','5','9','7','6','1','4','2','3'};
    // vector<char> a5{'4','2','6','8','5','3','7','9','1'};
    // vector<char> a6{'7','1','3','9','2','4','8','5','6'};
    // vector<char> a7{'9','6','1','5','3','7','2','8','4'};
    // vector<char> a8{'2','8','7','4','1','9','.','.','5'};
    // vector<char> a9{'3','4','5','2','8','6','.','7','9'};
    board.push_back(a1);
    board.push_back(a2);
    board.push_back(a3);
    board.push_back(a4);
    board.push_back(a5);
    board.push_back(a6);
    board.push_back(a7);
    board.push_back(a8);
    board.push_back(a9);
    Solution a;
    a.solveSudoku(board);cout<<endl;
        for(int i = 0;i < 9;i++){
            for(int j = 0;j < 9;j++){
                cout<<board[i][j]<<' ';
            }cout<<endl;
        }
    return 0;
}