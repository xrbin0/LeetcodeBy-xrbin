#include "0000.h"



class Solution {
public://DP will be faster
    bool isScramble(string s1, string s2) {
        if(s1.size() != s2.size())return 0;
        if(!s1.size())return 1;
        if(s1.size() == 1 && s1[0] == s2[0])return 1;
        if(s1 == s2)return 1;
        if(myhash(s1, 0, s1.size() - 1) != myhash(s2, 0, s2.size() - 1)) return 0;
        
        int size = s1.size();
        bool res = 0;
        for(int i = 1;!res && i < size;i++){
            string str11(s1,0,i);
            string str12(s1,i,size-i);
            string str21(s2,0,i);
            string str22(s2,i,size-i);
            res = res | (isScramble(str11, str21) & isScramble(str12, str22));
        }
        for(int i = 1;!res && i < size;i++){
            string str11(s1,0,i);
            string str12(s1,i,size-i);
            string str21(s2,0,size - i);
            string str22(s2,size - i,i);
            res = res | (isScramble(str11, str22) & isScramble(str12, str21));
        }
        return res;
    }
    int myhash(string str,int begin, int end){
        int sum = 0;
        for(;begin <= end;begin++){
            sum += (str[begin] - '0') * (str[begin] - '0') - (str[begin] - '0');
        }
        return sum;
    }
};

        //DP

        // vector <vector<bool> >dp(s1.size() + 3, vector<bool>(s1.size() + 3, 0));
        // for(int i = 0;i < size;i++)
        //     dp[i][i] = (s1[i] == s2[i]);
        // for(int i = 1;i < size;i++){
        //     for(int j = 0;j < size - i;j++){
        //         dp[j][i+j];
        //         for(int k = )
        //     }
        // }



// class Solution {
// public://这个代码只支持交换一次，但是扰乱字符串可以不停的交换，是我理解错了题意。
    // bool isScramble(string s1, string s2) {
    //     if(s1.size() != s2.size())return 0;
    //     if(!s1.size())return 1;
    //     if(s1 == "abc")return 1;
    //     int size = s1.size();
    //     vector <bool>dp(size + 3, 0);
    //     dp[0] = (s1[0] == s2[0]);
    //     for(int i = 1;i < size;i++){
    //         dp[i] = func1(s1, s2, i);
    //         if(s1[i] == s2[i])
    //             dp[i] = dp[i] | dp[i-1];
    //     }
    //     return dp[size - 1];
    // }
//     bool func1(const string& s1, const string& s2, int ind){
//         bool flag = 0;
//         for(int i = 0;!flag && i < ind;i++){
//             if(s1[i] == s2[ind]){
//                 int count = i;
//                 for(;!flag && count >= 0 && s1[count] == s2[ind - i + count];count--){
//                     for(int j = ind;j > i;j--){
//                         // cout<<s1[j]<<" "<<s2[j - (i - count + 1)]<<endl;
//                         // cout<<j<<" "<<i<<endl;
//                         if(s1[j] != s2[j - (i - count + 1)]){
//                             break;
//                         }else{
//                             if(j == i + 1){
//                                 flag = 1;
//                                 break;
//                             }
//                         }
//                     }
//                 }
//             }
//         }
//         return flag;
//     }
//     bool func2(const string& s1, const string& s2, int ind){
//         return 0;
//     }
// };

int main(){
    Solution a;
    string b1("abcdea");
    string b2("acdeba");
    cout<<a.func1(b1,b2,4)<<endl;
    return 0;
}