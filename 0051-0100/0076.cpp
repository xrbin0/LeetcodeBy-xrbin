#include "0000.h"

class Solution {
public:
    string minWindow(string s, string t) {
        int size = s.size(), tsize = t.size();
        if(size < tsize) return "";
        map <char, int> alph;
        int counts = 0, numOfalph = 0;
        for(int i = 0;i < tsize;i++){
            if(alph[t[i]] == 0) numOfalph++;//计算不同的字符的个数
            alph[t[i]] += 1;//利用map记录t中的各个字符的个数
        }
        // cout << alph['A'] << " " << alph['B'] << " " << alph['C'] << endl;

        int resBegin = 0, resSize = 0x7fffffff;
        int r = 0, l = 0;
        enum {R, L} state = R;
        while(true){
            // cout<<l<<" "<<r<<endl;
            switch (state){
                case R:
                    if(r >= size) state = L;
                    if(t.find(s[r]) == -1) {
                        r++; break;
                    }
                    alph[s[r]]--;
                    if(alph[s[r]] == 0) counts++;
                    if(counts == numOfalph)//所有的字符都出现了足够的次数了
                        state = L;
                    r++;
                    break;
                case L:
                    if(l >= size && resSize != 0x7fffffff)return string(s, resBegin, resSize);
                    else if(l >= size) return "";
                    if(l == r) state = R;
                    if(t.find(s[l]) == -1) {
                        l++;
                        break;
                    }

                    alph[s[l]]++;
                    if(alph[s[l]] == 1){
                        if(r - l < resSize && counts == numOfalph) { resBegin = l; resSize = r - l; }
                        counts--;
                        if(r >= size && resSize != 0x7fffffff) return string(s, resBegin, resSize);
                        else if(r >= size) return "";
                        state = R;
                    }
                    l++;
                    break;
                default: break;
            }
        }
        return "";
    }
};


// class Solution {
    // public:
    //     int res;int resmin, resmax;
    //     vector <int> tores;
    //     string minWindow(string s, string t) {
    //         res = 0x7FFFFFFF;
    //         vector <bool> alph(128 + 1, 0);
    //         int ssize = s.size();
    //         int tsize = t.size();
    //         for(int i = 0;i < tsize;){
    //             if(alph[t[i]]){
    //                 t.erase(t.begin() + i);
    //             }else{
    //                 alph[t[i]] = 1;
    //                 i++;
    //             }
    //         }
    //         map <char, vector<int> > pre;
    //         for(int i = 0;i < ssize;i++){
    //             if(alph[s[i]]){
    //                 pre[s[i]].push_back(i);
    //             }
    //         }
    //         return string(s, resmin, resmax - resmin + 1);
    //     }
    //     void func(int ind, string t, map <char, vector<int> >& pre){
    //         if(ind == t.size()){
    //             query();
    //             return;
    //         }
    //         for(int i = 0;i < pre[t[ind]].size();i++){
    //             tores.push_back(pre[t[ind]][i]);
    //             func(ind + 1, t, pre);
    //             tores.pop_back();
    //         }
    //     }
    //     void query(){
    //         int min = 0x7fffffff, max = 0x80000000;
    //         for(int i = 0;i < tores.size();i++){
    //             if(tores[i] > max)max = tores[i];
    //             if(tores[i] < min)min = tores[i];
    //         }
    //         if(max - min < res){
    //              res = max - min;
    //              resmax = max;
    //              resmin = min;
    //         }
    //     }
    // };