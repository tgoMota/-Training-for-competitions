#include <stdio.h>

int main(){

    float n1, n2;
    scanf("%f%f", &n1, &n2);

    if(n1 == 1){
        printf("Total: R$ %.2f\n", n2*4);
    }
    else if(n1 == 2){
        printf("Total: R$ %.2f\n", n2*4.50);
    }
    else if(n1 == 3){
        printf("Total: R$ %.2f\n", n2*5);
    }
    else if(n1 == 4){
        printf("Total: R$ %.2f\n", n2*2);
    }
    else{
        printf("Total: R$ %.2f\n", n2*1.50);
    }

return 0;
}
