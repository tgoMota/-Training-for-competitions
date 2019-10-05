#include <stdio.h>

int main(){

    int e1, e2, at, d;
    double p;

    while(scanf("%d%d%d%d", &e1, &e2, &at, &d) && (e1 != 0 || e2 != 0 || at != 0 || d != 0)){
        p = 1.0;
        at = 6.0-at;
        while(e1 > 0){
            p*= (double)(at/6.0);
            e1 -= d;
        }
        p = 1.0 - p;
        p *= 100;
        printf("%.1lf\n", p);
    }

return 0;
}
