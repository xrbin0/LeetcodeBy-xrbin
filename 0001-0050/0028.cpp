#include "0000.h"

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size() == 0)return 0;
        if(haystack.size() == 0)return -1;
        int res = haystack.find(needle);
        if(res != haystack.npos)return res;
        return -1;
    }
};