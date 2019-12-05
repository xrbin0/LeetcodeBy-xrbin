#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <stdio.h>
#define max(a,b) ( ((a)>(b)) ? (a):(b) )
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0)return 0;
        if(s.size() == 1)return 1;
        int res = 0;
        int begin = 0, end = 1;
        bool alph[128] = {0};
        alph[s[0]] = 1;
        // for(int i = 0;i < 128;i++)cout<<alph[i]<<" ";system("pause");
        while(1){
            if(alph[s[end]] == 1){
                res = (end - begin) > res?(end - begin):res;
                for(;s[begin] != s[end];begin++){
                    // cout<<begin<<" "<<end<<endl;
                    alph[s[begin]] = 0;
                }
                begin++;
            }
            alph[s[end]] = 1;
            end++;
            if(end == s.size()){
                res = (end - begin) > res?(end - begin):res;
                break;
            }
        }
        return res;
    }
};

// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         return func(s);
//     }
    
//     int func(string s){
//         if(s.size() == 0)return 0;
//         // cout<<s<<endl;
//         int size = s.size();
//         char *res = new char[size + 3];

//         for(int i = 0;i < size;i++){
//             res[i] = 1;
//         }
//         for(int i = 1;i < size;i++){
//             for(int j = 0;j + i < size;j++){
//                 int res1 = detection(s, j, i + j, 1);
//                 int res2 = detection(s, j, i + j, 0);
//                 // cout<<res1 << " " <<res2<<" "<<res[i - 1][j] << " " <<  res[i - 1][j + 1]<<endl;
//                 // for(int i = 0;i < size;i++){
//                 //     for(int j = 0;j < size; j++){
//                 //         cout << res[i][j] << " ";
//                 //     }cout<<endl;
//                 // }cout<<endl;
//                 res1 = max(res1, res2);
//                 if(res[j] > res[j + 1])
//                     res2 = res[j];
//                 else res2 = res[j + 1];
//                 res[j] = max(res1, res2);
//             }
//         }
//         int rets = res[0];
//         delete []res;
//         return rets;
//     }

//     int detection(const string s, int begin, int end, bool flag){
        
//         bool alp[128] = {0};
//         int remend = end;
//         int rembegin = begin;
//         if(flag){
//             for(;begin <= end;end--){
//                 if(alp[s.at(end)])return remend - end;
//                 alp[s.at(end)] = 1;
//             }
//         }
//         else{
//             for(;begin <= end;begin++){
//                 if(alp[s.at(begin)])return begin - rembegin;
//                 alp[s.at(begin)] = 1;
//             }
//         }
//         return remend - rembegin + 1;
//     }
// };


int main(){
    string s;
    cin>>s;
    Solution a;
    cout<<a.lengthOfLongestSubstring(s);
    cout<<"\n";
    system("pause");
    int as;
    cin>>as;
    return 0;
}
//asdasgksjkuencmfjgkhmykiecmdlowmwncudqwertujhbgmvkdlcxsp