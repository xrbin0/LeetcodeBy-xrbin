#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;
class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        vector <bool> res;
        int size = queries.size();
        int length = s.size();
        // cout<<length<<endl;
        int **alphabet = new int*[length + 3];
        int a[26] = {0};
        for(int i = 0;i < length + 3;i++){
            alphabet[i] = new int[26];
            for(int k = 0;k < 26;k++){
                alphabet[i][k] = 0;
            }
            // alphabet[i] = {0};
        }
        // cout<<sizeof(alphabet[1][0])<<endl;
        for(int i = 0;i < length;i++){
            a[(int)s.at(i) - 'a']++;
            for(int j = 0;j < 26;j++){
                alphabet[i + 1][j] = a[j];
            }
        }
        // for(int i = 0;i < length;i++){
        //     for(int j = 0; j < 26;j++){
        //         cout<<alphabet[i][j]<<" ";
        //     }cout<<endl;
        // }
        for(int j = 0;j < size;j++){
            int right = queries[j][0], left = queries[j][1], times = 2 * queries[j][2] + 1;

            for(int i = 0;i < 26;i++){
                if((alphabet[left + 1][i] - alphabet[right][i]) % 2 == 1)times--;
            }
            // cout<<times<<endl;
            if(times < 0)res.push_back(false);
            else res.push_back(true);
        }



            // temp.~basic_string();
        
        return res;
    }
};