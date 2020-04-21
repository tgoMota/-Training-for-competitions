#include <stdio.h>

int main(){

    double a, m = 0, i = 0;
    while(1){
        scanf("%lf", &a);
        if(a < 0 || a > 10)
            printf("nota invalida\n");
        else{
            ++i;
            m += a;
        }
        if(i == 2)
            break;
    }
    printf("media = %.2lf\n", m/2.0);

return 0;
}
