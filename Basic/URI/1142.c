#include <stdio.h>

int main(){

    int n, i = 1;
    scanf("%d", &n);
    while(n>0){
        printf("%d %d %d PUM\n", i, i+1, i+2);
        i+= 4;
        --n;
    }

return 0;
}
