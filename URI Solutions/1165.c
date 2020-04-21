#include <stdio.h>

int main(){

    int cont = 0, a, i, n;
    scanf("%d", &n);
    while(n > 0){
        scanf("%d", &a);
        cont = 0;
        for(i = 1 ; i < a ; ++i){
            if(a % i == 0)
                ++cont;
            if(cont == 2)
                break;
        }
        if(cont > 1)
            printf("%d nao eh primo\n", a);
        else
            printf("%d eh primo\n", a);

        --n;
    }

return 0;
}
