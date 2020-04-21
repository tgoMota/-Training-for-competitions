#include <stdio.h>

int main(){

    int n1, n2, n3, a[3], aux, i = 0;
    scanf("%d%d%d", &n1, &n2, &n3);
    a[0] = n1;
    a[1] = n2;
    a[2] = n3;

    while(i < 3){
        if(i != 2 && a[i] > a[i+1]){
            aux = a[i+1];
            a[i+1] = a[i];
            a[i] = aux;
            i = -1;
        }
        ++i;
    }

    printf("%d\n%d\n%d\n\n%d\n%d\n%d\n", a[0], a[1], a[2], n1, n2, n3);

return 0;
}
