#include <stdio.h>
#include <math.h>

int main(){
    int a, b, c;
    double p, at, ac, r, ye, pur, red;
    while(scanf("%d%d%d", &a, &b, &c) != EOF){
        p  = (a+b+c)/2.0;
        at = sqrt(p*(p-a)*(p-b)*(p-c));
        r  = (a*b*c)/(4.0*at);
        ac = M_PI * r * r;

        ye = ac - at; //yellow

        r = at/p;
        red = M_PI * r * r; //red

        pur = at - red; //purple

        printf("%.4lf %.4lf %.4lf\n", ye, pur, red);
    }

return 0;
}
