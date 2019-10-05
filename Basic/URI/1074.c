#include <stdio.h>

int main(){

    long int a;
    int n;
    scanf("%d", &n);
    while(n>0){
        scanf("%li", &a);
        if(a > 0 && (a % 2) == 0)
            printf("EVEN POSITIVE\n");
        if(a < 0 && a%2 == 0)
            printf("EVEN NEGATIVE\n");
        if(a > 0 && (a % 2) != 0)
            printf("ODD POSITIVE\n");
        if(a < 0 && a%2 != 0)
            printf("ODD NEGATIVE\n");
        if(a == 0)
            printf("NULL\n");
        --n;
    }

return 0;
}
