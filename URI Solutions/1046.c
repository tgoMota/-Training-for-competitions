#include <stdio.h>

int main(){

    int hi, hf, n = 0;
    scanf("%d%d", &hi, &hf);
    if(hi != hf){
        while(1){
            if(hi == hf){
                break;
            }
            ++hi;
            ++n;
            if(hi == 24)
                hi = 0;
        }
    }
    else
        n = 24;
    printf("O JOGO DUROU %d HORA(S)\n", n);

return 0;
}
