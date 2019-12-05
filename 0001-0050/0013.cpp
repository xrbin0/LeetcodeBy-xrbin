#include "0000.h"

int romanToInt(char* s) {
    int count = 0;
    for(int i =0;s[i] != '\0';i++){
        if(s[i] == 'M') count += 1000;
        else if(s[i] == 'D') count += 500;
        else if(s[i] == 'C') count += 100;
        else if(s[i] == 'L') count += 50;
        else if(s[i] == 'X') count += 10;
        else if(s[i] == 'V') count += 5;
        else if(s[i] == 'I') count += 1;
        if(s[i] != '\0' && s[i] == 'I' && s[i + 1] == 'V') count -= 2;
        else if(s[i] != '\0' && s[i] == 'I' && s[i + 1] == 'X') count -= 2;
        else if(s[i] != '\0' && s[i] == 'X' && s[i + 1] == 'L') count -= 20;
        else if(s[i] != '\0' && s[i] == 'X' && s[i + 1] == 'C') count -= 20;
        else if(s[i] != '\0' && s[i] == 'C' && s[i + 1] == 'D') count -= 200;
        else if(s[i] != '\0' && s[i] == 'C' && s[i + 1] == 'M') count -= 200;
    }
    return count;
}