#include <stdio.h>

int main(){

    int a, n100 = 0, n50 = 0, n20 = 0, n10 = 0, n5 = 0, n2 = 0, n1 = 0;
    scanf("%d", &a);
    printf("%d\n", a);
    while(a != 0){
        if(a >= 100){
            n100 = a/100;
            a = a % 100;
        }
        else if(a >= 50 ){
            n50 = a/50;
            a = a % 50;
        }
        else if(a >= 20){
            n20 = a/20;
            a = a % 20;
        }
        else if(a >= 10){
            n10 = a/10;
            a = a % 10;
        }
        else if(a >= 5){
            n5 = a/5;
            a = a % 5;
        }
        else if(a >= 2){
            n2 = a/2;
            a = a % 2;
        }
        else{
            n1 = a;
            break;
        }

    }
    printf("%d nota(s) de R$ 100,00\n", n100);
    printf("%d nota(s) de R$ 50,00\n", n50);
    printf("%d nota(s) de R$ 20,00\n", n20);
    printf("%d nota(s) de R$ 10,00\n", n10);
    printf("%d nota(s) de R$ 5,00\n", n5);
    printf("%d nota(s) de R$ 2,00\n", n2);
    printf("%d nota(s) de R$ 1,00\n", n1);

return 0;
}
