#include <stdio.h>

int main(){

    int pa = 0, im = 0, po = 0, neg = 0, i = 0, d;
    while(i < 5){
        scanf("%d", &d);
        if(d < 0)
            ++neg;
        if(d > 0)
            ++po;
        if(d % 2 == 0)
            ++pa;
        if(d % 2 != 0)
            ++im;
        ++i;
    }

    printf("%d valor(es) par(es)\n", pa);
    printf("%d valor(es) impar(es)\n", im);
    printf("%d valor(es) positivo(s)\n", po);
    printf("%d valor(es) negativo(s)\n", neg);

return 0;
}
