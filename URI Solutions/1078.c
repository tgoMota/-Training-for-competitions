#include <stdio.h>

int main(){
    int n, i = 1;
    scanf("%d", &n);
    while(i < 11){
        printf("%d x %d = %d\n", i, n, i*n);
        ++i;
    }

return 0;
}
