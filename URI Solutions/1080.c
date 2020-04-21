#include <stdio.h>

int main(){

    int d, i, m, p;

    for(i = 1; i <= 100 ; ++i){
        scanf("%d", &d);
        if(i == 1)
            m = d;
        if(m < d){
            m = d;
            p = i;
        }
    }
    printf("%d\n%d\n", m, p);

return 0;
}
