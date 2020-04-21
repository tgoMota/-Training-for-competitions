#include <stdio.h>

int main(){

    int hi, mi, hf, mf, th = 0, tm = 0;
    scanf("%d%d%d%d", &hi, &mi, &hf, &mf);
    th = tm = 0;
    if(hf > hi){
        if(mi > mf){
            th = hf - hi - 1;
            tm = 60 - (mi - mf);
        }else{
            th = hf-hi;
            tm = mf - mi;
        }
    }
    else if(hi > hf){
        if(mi > mf){
            th = 24 - (hi - hf) - 1;
            tm = 60 - (mi - mf);
        }else{
            th = 24 - (hi - hf) - 1;
            tm = mf - mi;
        }
    }
    else{
        if(mi > mf){
            th = 23;
            tm = 60 - (mi - mf);
        }else{
            if(mi == mf)
                th = 24;
            else
                th = 0;
            tm = mf - mi;
        }
    }

    printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n", th, tm);
    return 0;
}
