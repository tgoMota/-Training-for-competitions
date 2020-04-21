#include <stdio.h>

int main(){

    int x, y, i, j, k = 1;
    scanf("%d%d", &y, &x);

    while(1){
        for(j = 1 ; j <= y ; ++j){
            if(j != y && k!=x)
                printf("%d ", k);
            if(j == y && k!=x || k == x)
                printf("%d\n", k);
            if(k == x)
                break;
            ++k;
        }
        if(k >= x)
            break;
    }

return 0;
}
