#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <stdio.h>
#include <algorithm>
using namespace std;




class Solution {
public:
    bool isMatch(string s, string p) {
        if(s.size() == 1){
            if(p[0] == '*'){
                for(int i = 1;i < p.size();){
                    if(p[i] == '*'){
                        p.erase(p.begin() + i);
                    }
                    else i++;
                }
                if(p.size() == 1)return 1;
                else if(p.size() > 2)return 0;
                else if(p[1] == '?' || p[1] == s[0])return 1;
                else return 0;
            }
        }
        while(s.size() != 0 && p.size() != 0){
            if(s[0] == p[0] || p[0] == '?'){
                s.erase(s.begin());
                p.erase(p.begin());
            }
            else break;
        }
        int sizes = s.size();
        int sizep = p.size();
        if(sizes == 0 && sizep == 0)return 1;
        if(sizep == 0)return 0;
        if(sizes == 0 && p[0] != '*')return 0;
        if(sizes == 0 && p[0] == '*'){
            for(int i = 0;i < p.size();i++){
                if(p[i] != '*')return 0;
            }return 1;
        }
        bool ** dp = new bool* [sizes + 3];
        for(int i = 0;i < sizes + 3;i++){
            dp[i] = new bool[sizep + 3];
            for(int j = 0;j < sizep + 3;j++){
                dp[i][j] = 0;
            }
        }
        
        for(int i = 0;i < sizep;i++){
            if(s[0] == p[i]){
                dp[0][i] = 1;
                break;
            }
            else if(p[i] == '?'){
                dp[0][i] = 1;
                for(int j = i + 1;p[j] == '*';j++)dp[0][j] = 1;
                break;
            }
            else if(p[i] == '*'){
                dp[0][i] = 1;
            }
            else{
                break;
            }
        }
        for(int i = 0;i < sizes;i++){
            if(p[0] == '*')dp[i][0] = 1;
            else break;
        }

        for(int i = 1;i < sizes;i++)
        for(int j = 1;j < sizep;j++){
            if(p[j] == '*'){
                int temp = 0;
                for(int k = 0;k <= i;k++){
                    // if(i == 1 && j == 3)cout<<dp[i-1][k]<<"-";
                    temp |= dp[k][j-1];
                }
                dp[i][j] = temp;
            }else if(p[j] == '?'){
                dp[i][j] = dp[i - 1][j - 1];
            }else if(p[j] == s[i]){
                dp[i][j] = dp[i - 1][j - 1];
            }else{
                dp[i][j] = 0;
            }
        }
        // for(int i = 0;i < sizes;i++){
        //     for(int j = 0;j < sizep;j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        return dp[sizes - 1][sizep - 1];
    }
};

int main(){
    Solution a;
    string s("ab");
    string p("*?*?*");
    a.isMatch(s,p);

    return 0;
}