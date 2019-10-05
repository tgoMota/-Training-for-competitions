#include <stdio.h>

int main(){

    float a, media = 0;
    int np = 0, i = 0;
    while(i < 6){
        scanf("%f", &a);
        if(a > 0){
            ++np;
            media += a;
        }
        ++i;
    }
    media /= np;
    printf("%d valores positivos\n", np);
    printf("%.1f\n", media);

return 0;
}
