#include <stdio.h>

int main(){

    double n1, n2, n3, a[3], aux, r = 0;
    int i = 0;
    scanf("%lf%lf%lf", &n1, &n2, &n3);
    a[0] = n1;
    a[1] = n2;
    a[2] = n3;

    while(i < 3){
        if(i != 2 && a[i] < a[i+1]){
            aux = a[i+1];
            a[i+1] = a[i];
            a[i] = aux;
            i = -1;
        }
        ++i;
    }

    if(a[0] >= a[1] + a[2]){
        printf("NAO FORMA TRIANGULO\n");
    }
    else{
        if(a[0]*a[0] == a[1]*a[1] + a[2]*a[2]){
            printf("TRIANGULO RETANGULO\n");
        }
        if(a[0]*a[0] > a[1]*a[1] + a[2]*a[2]){
            printf("TRIANGULO OBTUSANGULO\n");
            r = 2;
        }
        else if(a[0]*a[0] < a[1]*a[1] + a[2]*a[2]){
            printf("TRIANGULO ACUTANGULO\n");
        }
        if(a[0] == a[1] && a[0] == a[2] && a[1] == a[2]){
            printf("TRIANGULO EQUILATERO\n");
        }
        else if(a[0] == a[1] || a[0] == a[2] || a[1] == a[2]){
            printf("TRIANGULO ISOSCELES\n");
        }
    }


return 0;
}
