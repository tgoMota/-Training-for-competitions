#include <stdio.h>

int main(){

    double a, b;
    char nome[50];
    scanf("%s%lf%lf", &nome, &a, &b);
    printf("TOTAL = R$ %.2lf\n", a + 0.15*b);

return 0;
}
