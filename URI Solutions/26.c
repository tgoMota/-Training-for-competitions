#include <stdio.h>

int somatorio(int n){

    int s = 0;

    for(int i = 0; i<=n ; ++i){
        s += i;
    }
    return s;
}

    int main()
 {

     int n;

     scanf("%d", &n);

     printf("O somatorio de 1 a %d = %d\n", n, somatorio(n));

     return 0;
 }
