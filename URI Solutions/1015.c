#include <stdio.h>
#include <math.h>

int main(){

    double p1x, p2x, p1y, p2y;
    scanf("%lf%lf%lf%lf", &p1x, &p1y, &p2x, &p2y);
    printf("%.4lf\n", sqrt((p2x-p1x)*(p2x-p1x) + (p2y-p1y)*(p2y-p1y)));

return 0;
}
