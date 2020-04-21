#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void convertFromDecToHex(unsigned long int num){
    if(num != 0){ //para hex
        unsigned long int r = num % 16;
        num /= 16;
        convertFromDecToHex(num);
        if(r < 10)
            printf("%lu", r);
        else{
            if(r == 10)
                printf("A");
            else if(r == 11)
                printf("B");
            else if(r == 12)
                printf("C");
            else if(r == 13)
                printf("D");
            else if(r == 14)
                printf("E");
            else if(r == 15)
                printf("F");
        }
    }
}

unsigned long int convertFromHexToDec(char *num){
    int l = strlen(num) - 1, d, i;
    unsigned long int soma = 0;
    for(i = 0; num[i] != 0 ; ++i){
        if(num[i] == 'a'){
            d = 10;
        }
        else if(num[i] == 'b'){
            d = 11;
        }
        else if(num[i] == 'c'){
            d = 12;
        }
        else if(num[i] == 'd'){
            d = 13;
        }
        else if(num[i] == 'e'){
            d = 14;
        }
        else if(num[i] == 'f'){
            d = 15;
        }
        else { //é um numero
            d = num[i] - '0';
        }
        soma += d*pow(16, l);
        --l;
    }
    return soma;
}

int main(){

    char nu[11];
    unsigned long int num;
    int i, k;
    while(1){
        scanf("%s", nu);
        if(nu[0] == '-')
            break;
        if(nu[1] == 'x'){ //hex
            k = 2;
            for(i = 0; nu[k] != 0 ; ++i){
                nu[i] = nu[k];
                ++k;
            }
            nu[i] = nu[k]; //'/0'
            printf("%lu\n",convertFromHexToDec(nu));
        }
        else{
          num = atol(nu);
          printf("0x");
          convertFromDecToHex(num);
          printf("\n");
        }
    }

return 0;
}
