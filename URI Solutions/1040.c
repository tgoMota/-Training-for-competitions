#include <stdio.h>

int main(){

    double a, b, c, d, m, k;

        scanf("%lf%lf%lf%lf", &a, &b, &c, &d);
        m = (2*a + 3*b + 4*c + d)/10.0;
        printf("Media: %.1lf\n", m);
        if(m >= 7.0)
            printf("Aluno aprovado.\n");
        else if(m >= 5.0){
            printf("Aluno em exame.\n");
            scanf("%lf", &k);
            printf("Nota do exame: %.1lf\n", k);
            m = (m+k)/2.0;
            if(m >= 5.0)
                printf("Aluno aprovado.\n");
            else
                printf("Aluno reprovado.\n");
            printf("Media final: %.1lf\n", m);
        }
        else{
            printf("Aluno reprovado.\n");
        }

return 0;
}
