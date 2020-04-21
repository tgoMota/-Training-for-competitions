#include <stdio.h>

int main(){

    int n, a, b, i, ni = 0, aux;
    scanf("%d", &n);
    while(n>0){
        scanf("%d%d", &a, &b);
        if(b > a){
            aux = a;
            a = b;
            b = aux;
        }
        --n;
        i = 0;
        ni = 0;
        for(i = b+1; i < a ; ++i){
            if(i % 2 != 0)
                ni += i;
        }
        printf("%d\n", ni);
    }

return 0;
}
