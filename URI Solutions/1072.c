#include <stdio.h>

int main(){

    int n, k, kin = 0, kout = 0;
    scanf("%d", &n);
    while(n>0){
        scanf("%d", &k);
        if(k >= 10 && k <= 20)
            ++kin;
        else
            ++kout;
        --n;
    }
    printf("%d in\n%d out\n", kin, kout);

return 0;
}
