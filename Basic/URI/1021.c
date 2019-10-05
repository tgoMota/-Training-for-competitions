#include <stdio.h>
#include <math.h>

int main(){

    double nu;
    int k, n;

    scanf("%lf", &nu);
    nu += 1e-9; //aumenta precisao
    n = (int)nu;
    printf("NOTAS:\n");
    k = n/100;
    n = n%100;
    printf("%d nota(s) de R$ 100.00\n", k);
    k = n / 50;
    n = n % 50;
    printf("%d nota(s) de R$ 50.00\n", k);
    k = n / 20;
    n = n % 20;
    printf("%d nota(s) de R$ 20.00\n", k);
    k = n / 10;
    n = n % 10;
    printf("%d nota(s) de R$ 10.00\n", k);
    k = n / 5;
    n = n % 5;
    printf("%d nota(s) de R$ 5.00\n", k);
    k = n / 2;
    n = n % 2;
    printf("%d nota(s) de R$ 2.00\n", k);
    k = n;

    printf("MOEDAS:\n");
    printf("%d moeda(s) de R$ 1.00\n", k);

    double v = modf(nu, &k); //centavos
    n = v*100;

    if(v >= 0.50){
        k = n/50;
        n = n%50;
    }
    printf("%d moeda(s) de R$ 0.50\n", k);

    if(v >= 0.25){
        k = n/25;
        n = n%25;
    }
    printf("%d moeda(s) de R$ 0.25\n", k);

    if(v >= 0.10){
        k = n/10;
        n = n%10;
    }
    printf("%d moeda(s) de R$ 0.10\n", k);

    if(v >= 0.05){
        k = n/5;
        n = n%5;
    }
    printf("%d moeda(s) de R$ 0.05\n", k);

    printf("%d moeda(s) de R$ 0.01\n", n);

return 0;
}
