#include <stdio.h>

int main(){

    int a, i;
    while(1){
        scanf("%d", &a);
        if(a == 0)
            break;
        for(i = 1; i <= a ; ++i){
          if(i != a)
                printf("%d ", i);
            else
                printf("%d", i);
        }
        printf("\n");
    }

return 0;
}
