#include <stdio.h>

int main(){

    int i = 1, j = 7, n = 0;
    while(1){
        printf("I=%d J=%d\n", i, j);
        --j;
        ++n;
        if(n == 3 && i == 9)
            break;
        if(n == 3){
            i += 2;
            j += 5;
            n = 0;
        }
    }

return 0;
}

