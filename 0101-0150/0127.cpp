#include "0000.h"

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        vector <int> flag(wordList.size(), 0);
        queue <int> q;
        int size = wordList.size();
        int depth = 0;
        for(int i = 0;i < size;i++){
            if(flag[i] == 0){
                if(eq(beginWord, wordList[i])){
                    q.push(i);
                    flag[i] = 1;
                }
            }
        }
        while(1){
            int a = q.front();
            if(eq(wordList[a], endWord))return flag[a];
            for(int i = 0;i < size;i++){
                if(flag[i] == 0){
                    if(eq(wordList[a], wordList[i])){
                        q.push(i);
                        flag[i] = flag[a] + 1;
                    }
                }
            }
        }
        return 0;
    }

    bool eq(string& a, string& b){
        if(a.size() != b.size())return false;
        int num = 0;
        for(int i = 0;i < a.size();i++){
            if(a[i] != b[i])num++;
        }
        return num <= 1;
    }
};