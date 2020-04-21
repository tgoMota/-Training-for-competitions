#include <stdio.h>

int main(){

    long long int n, i, j;
    while(scanf("%lli", &n) && n > 0){
        long long int v[n], fim;
        for(i = 0; i < n; ++i){
            v[i] = 0;
        }
        for(i = 1; i <= n ; ++i){
            if(i*i > n){
                break;
            }
            v[i*i - 1] = 1;
            fim = i*i - 1;
        }
        for(i = 0; i < n; ++i){
            if(v[i])
                printf("%lli", i+1);
            if(i != fim && v[i])
                printf(" ");
        }
        printf("\n");
    }

return 0;
}
