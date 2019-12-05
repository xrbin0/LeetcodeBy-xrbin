#include "0000.h"

class Solution {
public:
    int state[10][4] = {
    //       0-9 e  +-  .
    /*0*/    {2, -1, 1, 9},
    /*1*/    {2, -1, -1, 9},
    /*2*/    {2, 6, -1, 3},
    /*3*/    {5, 6, 4, -1},
    /*4*/    {5, -1, -1, -1},
    /*5*/    {5, 6, -1, -1},
    /*6*/    {8, -1, 7, -1},
    /*7*/    {8, -1, -1, -1},
    /*8*/    {8, -1, -1, -1},
    /*9*/    {5, -1, -1, -1}
    };
    bool isNumber(string s) {
        int curState = 0;
        while(s.size() > 0 && s[0] == ' '){
            s.erase(s.begin());
        }
        while(s.size() > 0 && s[s.size() - 1] == ' '){
            s.erase(s.end() - 1);
        }
        for(int i = 0;i < s.size();i++){
            switch (s[i]){
                case 'e':
                    if(state[curState][1] == -1) return false;
                    curState = state[curState][1];
                break;
                case '+': case '-':
                    if(state[curState][2] == -1) return false;
                    curState = state[curState][2];
                break;
                case '.':
                    if(state[curState][3] == -1) return false;
                    curState = state[curState][3];
                break;
                case '0': case '1': case '2': case '3': case '4':
                case '5': case '6': case '7': case '8': case '9':
                    if(state[curState][0] == -1) return false;
                    curState = state[curState][0];
                break;
                default: return false;
            }
        }
        if(curState == 2 || curState == 3 || curState == 5 || curState == 8) return true;
        return false;
    }
};