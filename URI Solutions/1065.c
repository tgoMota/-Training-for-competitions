#include <stdio.h>

int main(){

    int i = 0, np = 0, a;
    while(i < 5){
        scanf("%d", &a);
        if(a % 2 == 0)
            ++np;
        ++i;
    }
    printf("%d valores pares\n", np);

return 0;
}
