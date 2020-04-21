#include <stdio.h>
#include <math.h>

int main(){

    int a, b,c, soma = 0, i;
    scanf("%d%d", &a, &b);
    if(a > b){
        c = a;
        a = b;
        b = c;
    }
    for(i = a+1; i<b ; ++i){
        if(abs(i) % 2 == 1)
            soma += i;
    }
    printf("%d\n", soma);

return 0;
}
