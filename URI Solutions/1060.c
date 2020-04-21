#include <stdio.h>

int main(){

    int n = 0, pn = 0;
    float p;
    while(n<6){
        scanf("%f", &p);
        if(p > 0)
            ++pn;
        ++n;
    }
    printf("%d valores positivos\n", pn);

return 0;
}
