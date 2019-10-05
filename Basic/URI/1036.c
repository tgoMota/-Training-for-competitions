#include <stdio.h>
#include <math.h>

int main(){

    double a, b, c, delta, r1, r2;
    scanf("%lf%lf%lf", &a, &b, &c);
    delta = b*b - 4*a*c;
    if(delta>=0 && a != 0){
        delta = sqrt(delta);
        r1 = (-1*b + delta)/(2.0*a);
        r2 = (-1*b - delta)/(2.0*a);

        printf("R1 = %.5lf\n", r1);
        printf("R2 = %.5lf\n", r2);
    }
    else
        printf("Impossivel calcular\n");

return 0;
}
