#include "0000.h"

bool isPalindrome(int x) {
    if(x < 0) return false;
    else{
        char a[20];
        for(int i = 0;x != 0;x/=10,i++){
            a[i] = x % 10 + '0';
            a[i + 1] = '\0';
        }
        char b[20];
        unsigned i = 0;
        for(;a[i + 1] != '\0';i++);
        for(int j = 0;i != -1;i--,j++){
            b[j] = a[i];
        }
        for(int n = 0;a[n] != '\0';n++){
            if(a[n] != b[n])
                return false;
        }
        return true;
    }
}