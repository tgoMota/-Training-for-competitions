#include <stdio.h>

int main(){

    int n, nAlunos, i, nAcimaMedia , k;
    float porcentagem;
    long int media;
    scanf("%d", &n);
    int notas[n];
    while(n > 0){
        media = 0;
        nAcimaMedia = 0;
        scanf("%d", &nAlunos);
        for(i = 0; i < nAlunos ; ++i){
            scanf("%d", &notas[i]);
            media += notas[i];
        }
        media /= nAlunos;
        for(i = 0 ; i < nAlunos ; ++i){
            if(notas[i] > media)
                ++nAcimaMedia;
        }
        porcentagem = ((float)nAcimaMedia/(float)nAlunos)*100;
        printf("%.3f%%\n", porcentagem);
        --n;
    }

return 0;
}
