#include <stdio.h>

unsigned long long int fatorial(int num){
    unsigned long long int fat = 1, i;
    for(i = num; i > 0 ; --i){
        fat *= i;
    }
    return fat;
}

int main(){
    int num1, num2;
    unsigned long long int soma;
    while(scanf("%d%d", &num1, &num2) != EOF){
        soma = fatorial(num1) + fatorial(num2);
        printf("%llu\n", soma);
    }

return 0;
}
