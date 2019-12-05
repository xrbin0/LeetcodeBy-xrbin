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
        if(s.size() == 0 && p.size() == 0)return 1;
        if(p.size() == 0)return 0;
        if(s.size() == 0){
            if((p.size() & 1) == 1)return 0;
            for(int i = 0;((p.size() & 1) == 0) && 2*i + 1 < p.size();i++){
                // cout<<p[2*i + 1]<<endl;
                if(p[2*i + 1] != '*')return 0;
            }
            // cout<<"win!\n"<<endl;
            return 1;
        }
        char *c = new char[p.size() + 3];
        for(int i = 0;i < p.size();){
            if(p[i] == '*'){
                c[i - 1] = p[i - 1];
                p.erase(p.begin() + i - 1);
            }
            else i++;
        }
        int sizes = s.size();
        int sizep = p.size();
        // cout<<s<<" \n"<<p<<endl;
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
                for(int j = i + 1;p[j] == '*';j++)dp[0][j] = 1;
                break;
            }
            else if(p[i] == '.'){
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
            if(p[0] == '*' && (c[0] == s[i] || c[0] == '.'))dp[i][0] = 1;
            else break;
        }

        for(int i = 1;i < sizes;i++)
        for(int j = 1;j < sizep;j++){
            
            if(p[j] == '.'){
                dp[i][j] = dp[i - 1][j - 1];
            }else if(p[j] == s[i]){
                dp[i][j] = dp[i - 1][j - 1];
            }else if(p[j] == '*'){
                int temp = 0;
                    temp |= dp[i][j-1];
                for(int k = i;(c[j] == s[k] || c[j] == '.') && k > 0;k--){
                    // if(i == 5 && j == 2){
                    //     cout<<dp[i-1][k]<<"-";
                        // cout<<c[j]<<" "<<s[k]<<endl;
                    // }
                    temp |= dp[k - 1][j-1];
                }
                dp[i][j] = temp;
            }
            else{
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
    string s("");
    string p("..ac");
    cout<<a.isMatch(s,p);

    return 0;
}

// class Solution {
// public:
//     bool isMatch(string s, string p) {
//         stack<int>ss;
//         stack<int>ps;
//         if(s.size() == 0)return true;
//         if(p.size() == 0)return false;

//         // for(int i = 1;i < p.size() - 1;){
//         //     if(p[i] == '*' && p[i - 1] == p[i + 1]){
//         //         p.erase(p.begin() + i + 1);
//         //     }
//         //     else i++;
//         // }

//         string::iterator sbegin = s.begin();
//         string::iterator pbegin = p.begin();
//         bool res = false;
//         while(pbegin < p.end() && sbegin < s.end()){
//             if(pbegin[0] == '.' && pbegin[1] != '*'){
//                 // cout<<"."<<endl;
//                 // cout<<sbegin[0]<<endl;
//                 sbegin++;pbegin++;
//             }
//             else if(pbegin[0] == '.' && pbegin[1] == '*'){
//                 // cout<<".*"<<endl;

//                 cout<<"stack!"<<endl;
//                 ss.push(sbegin - s.begin());
//                 ps.push(pbegin - p.begin() + 2);

//                 if(pbegin[2] == '.'){
//                     while(sbegin < s.end()){
//                         cout<<"stack!"<<endl;
//                         ss.push(sbegin - s.begin() + 1);
//                         ps.push(pbegin - p.begin() + 2);
//                         sbegin++;
//                     }
//                 }
//                 else {
//                     while(sbegin < s.end() && pbegin[2] != sbegin[0]){
//                         sbegin++;
//                     }

//                     if(sbegin != s.end()){
//                         // cout<<"stack!"<<endl;
//                         ss.push(sbegin - s.begin() + 1);
//                         // cout<<ss.top()<<endl;
//                         ps.push(pbegin - p.begin());
//                         // cout<<ps.top()<<endl;
//                     }
//                     sbegin++;
//                     pbegin+=2;
//                 }
//             }
//             else if(sbegin[0] == pbegin[0]){
//                 // cout<<"=="<<endl;
//                 if(pbegin[1] == '*'){
//                     // cout<<"stack!"<<endl;
//                     ss.push(sbegin - s.begin());
//                     // cout<<ss.top()<<endl;
//                     ps.push(pbegin - p.begin() + 2);
//                     // cout<<ps.top()<<endl;
//                 }
//                 sbegin++;
//                 if(pbegin[1] != '*')pbegin++;
//             }else if(pbegin[1] == '*'){
//                 // cout<<"!=*"<<endl;
//                 pbegin+=2;
//             }
//             else{
//                 if(!ss.empty()){
//                     while(!ss.empty() && sbegin >= s.end() || pbegin >= p.end()){
//                         // cout<<"unstack1!"<<endl;
//                         sbegin = ss.top() + s.begin();
//                         // cout<<ss.top()<<endl;
//                         pbegin = ps.top() + p.begin();
//                         // cout<<ps.top()<<endl;
//                         ss.pop();ps.pop();
//                     }
//                 }else{
//                     break;
//                 }
                
//             }
//             if(pbegin >= p.end() && sbegin >= s.end()){
//                 // cout<<"win1"<<endl;
//                 return 1;
//             }
//             else if((sbegin >= s.end()) && (pbegin == p.end() - 2) && pbegin[1] == '*'){
//                 // cout<<"win2"<<endl;
//                 return 1;
//             }
//             else if(pbegin >= p.end() || sbegin >= s.end()){
//                 if(!ss.empty()){
//                     while(!ss.empty() && sbegin >= s.end() || pbegin >= p.end()){
//                         // cout<<"unstack1!"<<endl;
//                         sbegin = ss.top() + s.begin();
//                         // cout<<ss.top()<<endl;
//                         pbegin = ps.top() + p.begin();
//                         // cout<<ps.top()<<endl;
//                         ss.pop();ps.pop();
//                     }
//                 }else{
//                     break;
//                 }
//             }
//         }
//         return res;
//     }
// };