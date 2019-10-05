#include <stdio.h>

int main(){

    int n, i = 0, k;
    scanf("%d", &n);
    k = n;
    while(i<6){
        if(k % 2 == 1){
            printf("%d\n", k);
            ++i;
            k += 2;
        }
        else
            ++k;
    }

return 0;
}
