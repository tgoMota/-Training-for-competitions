#include <stdio.h>

int main(){

    int n, i, k;
    unsigned long long int num1, num2;
    scanf("%d", &n);
    while(n > 0){
        scanf("%llu%llu", &num1, &num2);
        k = 0;
        for(i = 0;  ; ++i){
            if(num1 % 10 != num2 % 10 || num1 == 0 && num2 != 0){
                k = 1;
                break;
            }
            num1 /= 10;
            num2 /= 10;
            if(num2 == 0)
                break;
        }
        if(k)
            printf("nao encaixa\n");
        else
            printf("encaixa\n");
        --n;
    }

return 0;
}
