#include <stdio.h>
#include <math.h>

int main(){

    int n, c;
    unsigned long long int x, i;
    scanf("%d", &n);
    while(n>0){
        scanf("%llu", &x);
        c = 0;
        for(i = 1; i <= sqrt(x) ; ++i){
            if(x % i == 0)
                ++c;
            if(c > 1){
                printf("Not Prime\n");
                break;
            }
        }
        if(c == 1)
            printf("Prime\n");
        --n;
    }

return 0;
}
