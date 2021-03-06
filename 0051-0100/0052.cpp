#include "0000.h"


class Solution {
public:
    int totalNQueens(int n) {
        vector<vector<string> > t = solveNQueens(n);
        return t.size();
    }
    vector<vector<string> > res;
    vector<string> ares;
    int m;
    vector<vector<string> > solveNQueens(int n) {
        m = n;
        vector<bool> flag(n, 0);
        string row(n, '.');
        for(int i = 0;i < n;i++)ares.push_back(row);
        func(0, flag);
        return res;
    }
    void func(int ind, vector<bool> &flag){
        if(ind == m)res.push_back(ares);
        for(int i = 0;i < m;i++){
            if(flag[i] == 0 && judge(ind, i)){
                ares[ind][i] = 'Q';
                flag[i] = 1;
                func(ind + 1, flag);
                flag[i] = 0;
                ares[ind][i] = '.';
            }
        }
    }
    bool judge(int i, int j){
        ares[i][j] = 'Q';
        vector <bool> a(2 * m, 0);
        vector <bool> b(2 * m, 0);
        
        for(int i = 0;i < m;i++){
            for(int j = 0;j < m;j++){
                if(ares[i][j] == 'Q'){
                    if(a[i-j + m]){
                        ares[i][j] = '.';
                        return 0;
                    }
                    else a[abs(i-j + m)] = 1;
                    
                    if(b[abs(i+j)]){
                        ares[i][j] = '.';
                        return 0;
                    }
                    else b[abs(i+j)] = 1;
                }
            }
        }
        ares[i][j] = '.';
        return 1;
    }
};