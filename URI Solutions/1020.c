#include<stdio.h>

int main(){

    int i, a, m, d;
    scanf("%d", &i);
    a = i/365;
    i = i % 365;
    m = i/30;
    i = i % 30;
    d = i;
    printf("%d ano(s)\n", a);
    printf("%d mes(es)\n", m);
    printf("%d dia(s)\n", d);

return 0;
}
