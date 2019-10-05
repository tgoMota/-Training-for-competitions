#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    unsigned long int num1, num2;
    int soma = 0, op, vaiUm = 0;
    while(1){
        scanf("%lu%lu", &num1, &num2);
        if(num1 == 0 && num2 == 0)
            exit(1);
        op = 0;
        vaiUm = 0;
        while(1){
            soma = num1 % 10 + num2 % 10 + vaiUm;
            if(soma >= 10){
                ++op;
                vaiUm = 1;
            }
            else
                vaiUm = 0;
            num1 /= 10;
            num2 /= 10;
            if(num1 == 0 && num2 == 0)
                break;
        }
        if(op == 0)
            printf("No carry operation.\n");
        else if(op == 1)
            printf("1 carry operation.\n");
        else
            printf("%d carry operations.\n", op);
    }

return 0;
}
