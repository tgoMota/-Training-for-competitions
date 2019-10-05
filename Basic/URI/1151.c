#include <stdio.h>

int main(){

    int n, i;
    scanf("%d", &n);
    int v[n];
    for(i = 0; i < n ; ++i){
        if(i == 0){
            v[i] = 0;
        }
        else if(i == 1){
            v[i] = 1;
        }
        else{
            v[i] = v[i-1] + v[i-2];
        }
        if(i != n-1)
            printf("%d ", v[i]);
        else
            printf("%d\n", v[i]);
    }

return 0;
}
