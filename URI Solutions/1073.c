#include <stdio.h>

int main(){

    unsigned long long int n, i = 2;
    scanf("%llu", &n);
    while(i<= n){
        printf("%llu^2 = %llu\n", i, i*i);
        i+=2;
    }
    return 0;
}
