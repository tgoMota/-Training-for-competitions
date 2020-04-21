#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

void convertFromDecToBin(long long int num){
    if(num != 0){ //para bin
        long long int r = num % 2;
        num /= 2;
        convertFromDecToBin(num);
        printf("%lli", r);
    }
}

void convertFromDecToHex(long long int num){
    if(num != 0){ //para hex
        long long int r = num % 16;
        num /= 16;
        convertFromDecToHex(num);
        if(r < 10)
            printf("%lli", r);
        else{
            if(r == 10)
                printf("a");
            else if(r == 11)
                printf("b");
            else if(r == 12)
                printf("c");
            else if(r == 13)
                printf("d");
            else if(r == 14)
                printf("e");
            else if(r == 15)
                printf("f");
        }
    }
}

long long int convertFromBinToDec(char *num){
    int i, l = strlen(num) - 1;
    long long int soma = 0, d;
    char t;
    for(i = 0; num[i] != 0 ; ++i){
        d = num[i] - '0'; //digito unidade
        soma += (long long int)(d*pow(2,l));
        --l;
    }
    return soma;
}

long long int convertFromHexToDec(char *num){
    int l = strlen(num) - 1, d, i;
    long long int soma = 0;
    for(i = 0; num[i] != 0 ; ++i){
        tolower(num[i]);
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

    int n;
    char tipo[4], nu[33], t;
    int caso = 1;
    long long int num, decimal;
    scanf("%d", &n);
    while(n>0){
        scanf("%s%s", nu, tipo);
        num = atoll(nu);
        printf("Case %d: \n", caso);
        if(strcmp(tipo, "bin") == 0){
            decimal = convertFromBinToDec(nu);
            printf("%lli dec\n", decimal);
            convertFromDecToHex(decimal);
            printf(" hex\n");
        }
        else if(strcmp(tipo, "dec") == 0){
            convertFromDecToHex(num);
            printf(" hex\n");
            convertFromDecToBin(num);
            printf(" bin\n");
        }
        else if(strcmp(tipo, "hex") == 0){
            decimal = convertFromHexToDec(nu);
            printf("%lli dec\n", decimal);
            convertFromDecToBin(decimal);
            printf(" bin\n");
        }
        --n;
        ++caso;
        printf("\n");
    }

return 0;
}
