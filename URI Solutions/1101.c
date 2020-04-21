#include <stdio.h>

int main(){

    int m, n, i, j, aux, sum = 0;
    while(1){
        scanf("%d%d", &m, &n);
        if(m <= 0 || n <= 0)
            break;
        if(m > n){
            aux = m;
            m = n;
            n = aux;
        }
        sum = 0;
        for(j = m; j <= n ; ++j){
            printf("%d ", j);
            sum += j;
        }
        printf("Sum=%d\n", sum);
        getchar();
    }

return 0;
}
