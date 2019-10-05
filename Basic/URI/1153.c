#include <stdio.h>

int main(){

    int f = 1, a, i;
    scanf("%d", &a);
    for(i = a; i > 0 ; --i){
        f *= i;
    }
    printf("%d\n", f);

return 0;
}
