#include <stdio.h>

int main(){

    int n, h, m, s;
    scanf("%d", &n);
    h = n/3600;
    n = n % 3600;
    m = n/60;
    n = n % 60;
    s = n;
    printf("%d:%d:%d\n", h, m, s);

return 0;
}
