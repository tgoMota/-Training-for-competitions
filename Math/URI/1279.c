#include <stdio.h>

int main(){

    int k, a = 0, l = 0;

    while(1){
        if(a>0)
            printf("\n");
        if(scanf("%d", &k) == EOF)
            break;

        if(k % 400 == 0 || k % 4 == 0 && k % 100 != 0){
            if(k % 400 == 0){
                printf("This is leap year.\n");
                ++l;
            }
            if(k % 15 == 0){
                printf("This is huluculu festival year.\n");
                ++l;
            }
            if(k % 55 == 0){
                    ++l;
                    if(k % 400 != 0)
                        printf("This is leap year.\n");

                printf("This is bulukulu festival year.\n");
            }
            if(l == 0)
               printf("This is an ordinary year.\n");
        }
        else{
            if(k % 15 == 0)
                printf("This is huluculu festival year.\n");
            else
                printf("This is an ordinary year.\n");
        }
    ++a;

    }

    return 0;
}

