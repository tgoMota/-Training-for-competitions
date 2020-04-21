#include <stdio.h>

int main(){
    int d;
    while(1){
        scanf("%d", &d);
        if(d != 2002)
            printf("Senha Invalida\n");
        else{
            printf("Acesso Permitido\n");
            break;
        }
    }

return 0;
}
