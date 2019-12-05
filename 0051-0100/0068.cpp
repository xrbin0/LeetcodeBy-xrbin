#include "0000.h"
class Solution {
public:
    vector<string> res;
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int befoi = 0;
        int sums = 0;
        while(befoi < words.size()){
            sums = 0;
            for(int i = befoi;i < words.size();i++){
                sums += words[i].size() + 1;
                if(sums > maxWidth + 1){
                    string ares = "";
                    if(i - befoi == 1){
                        ares += words[befoi];
                        for(;ares.size() < maxWidth;)ares += " ";
                    }else{
                        sums -= (words[i].size() + 1);
                        sums = maxWidth - sums + (i - befoi);//number of space
                        // cout<<sums<<endl;
                        int div = sums / (i - befoi - 1);
                        int mod = sums % (i - befoi - 1);
                        // cout<<mod<<" "<<div<<endl;
                        for(int k = 0;k < mod;k++){
                            ares += words[befoi + k];
                            ares += string(div+1,' ');
                        }
                        for(;(i - befoi - 1) >= mod;mod++){
                            ares += words[befoi + mod];
                            if((i - befoi - 1) > mod)
                                ares += string(div,' ');
                        }
                    }
                    res.push_back(ares);
                    befoi = i;
                    break;
                }else if(i == words.size() - 1){
                    string ares = "";
                    for(int k = befoi;k <= i;k++){
                        ares += words[k];
                        ares += " ";
                    }
                    for(;ares.size() < maxWidth;)ares += " ";//remember
                    for(;ares.size() > maxWidth;)ares.pop_back();//remember
                    befoi = i + 1;
                    res.push_back(ares);
                    break;
                }
            }
        }
        return res;
    }
};