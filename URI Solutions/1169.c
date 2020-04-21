#include <stdio.h>

int main(){

    int n, x, i;
    unsigned long long int peso, atual;

    scanf("%d", &n);
    while(n>0){
        peso = 0;
        atual = 1;
        scanf("%d", &x);
        for(i = 0; i < x ; ++i){
            peso += atual;
            if(i != 63)
                atual *= 2;
        }
        --n;
        if(i == 64)
            atual /= 6000;
        else
            atual /= 12000;
        printf("%llu kg\n", atual);
    }

return 0;
}
