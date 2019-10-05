#include <stdio.h>

int main(){

    int n;
    double a, b;
    scanf("%d", &n);
    while(n>0){
        scanf("%lf%lf", &a, &b);
        if(b != 0)
            printf("%.1lf\n", a/b);
        else
            printf("divisao impossivel\n");
        --n;
    }

return 0;
}
