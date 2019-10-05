#include <stdio.h>

int main(){

    long int a, b, soma = 0, i, aux;
    scanf("%li%li", &a, &b);
    if(b < a){
        aux = b;
        b = a;
        a = aux;
    }
    for(i = a; i<=b ; ++i){
        if(i % 13 != 0)
            soma += i;
    }
    printf("%li\n", soma);

return 0;
}
