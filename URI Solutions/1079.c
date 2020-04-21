#include <stdio.h>

int main(){

    int n;
    double a, b, c, m = 0;
    scanf("%d", &n);
    while(n > 0){
        scanf("%lf%lf%lf", &a, &b, &c);
        m = a*2.0 + b*3.0 + c*5.0;
        m /= 10.0;
        printf("%.1lf\n", m);
        --n;
    }

return 0;
}
