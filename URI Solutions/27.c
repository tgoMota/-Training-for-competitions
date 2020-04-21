#include <stdio.h>
#include <math.h>
#define pi 3.141593;

int fat(int n){
    if(n==0)
        return 1;
    else
        return n*fat(n-1);
    }

float sina(int x){
    float a = 0, b = 1;
    int n = 5;

    for(int i = 0; i <= n ; ++i){
        if(i % 2 == 0){
            a += (pow(x,b)/fat(b));
        }
        else
            a -= (pow(x,b)/fat(b));

        b = b*2;
    }
    }

int main() {

    int x, a;

    printf("%d\n", fat(3));

    scanf("%d", &x);

    printf("sen(%d) = %f\n", x, sina(x));

return 0;
}
