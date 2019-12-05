
#include "0000.h"

int reverse(int x) {
    int a = 0,b = 0;
    for(;x != 0;x = x/10){
        b = 10 * a + x % 10;
        if((b - x % 10)/10 != a) return 0;
        a = b;
    }
    return a;
}