#include <stdio.h>

int main(){

    double a, b, c, ab, bc, ca;
    scanf("%lf%lf%lf", &a, &b, &c);

    ab = b - a;
    bc = b - c;
    ca = c - a;

    if(ab < 0)
        ab *= -1;
    if(bc < 0)
        bc *= -1;
    if(ca < 0)
        ca *= -1;

    if(bc < a && b + c > a && ca < b && a + c > b && ab < c && b + a > c){
        printf("Perimetro = %.1lf\n", a+b+c);
    }
    else
        printf("Area = %.1lf\n", ((a+b)*c)/2.0);

return 0;
}
