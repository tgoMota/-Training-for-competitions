#include <stdio.h>

int main(){

    int n = 0;
    double i = 0, j = 1, k = 0;
    while(1){
        printf("I=%g J=%g\n", i, j);
        ++j;
        ++n;
        if(n == 3 && i == 2)
            break;
        if(n == 3){
            ++k;
            i = 0.2*k;
            j = 1.0 + 0.2*k;
            n = 0;
        }
    }

return 0;
}

