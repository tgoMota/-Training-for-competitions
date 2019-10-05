#include <stdio.h>
#include <math.h>

int main(){

    int d, vf, vg;
    float tf, tg, sg;
    while(scanf("%d%d%d", &d, &vf, &vg) != EOF){
        sg = pow(d, 2) + 144; //triangulo retangulo
        sg = sqrt(sg);
        tg = sg/(float)vg;
        tf = 12/(float)vf;
        if(tg <= tf)
            printf("S\n");
        else
            printf("N\n");
    }

return 0;
}
