#include <stdio.h>
#include <math.h>

int main(){

    int n;
    long long int k, r;
    scanf("%d", &n);
    while(n-->0 && scanf("%lli", &k)){
        r = (sqrt(1+8*k)-1)/2;
        printf("%lli\n", r);
    }

return 0;
}
