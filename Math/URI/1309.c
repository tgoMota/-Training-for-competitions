#include <stdio.h>
#include <string.h>

int main(){

    char d[200];
    int count, i,c,cz, k, l;

    while(scanf("%s%d", &d, &c) != EOF){
        k = strlen(d);
        cz = 0;
        for(i = 0; d[i] == '0' ; ++i, ++cz){}
        k -= cz;
        count = (k % 3) - 1;
        printf("$");
        l = 0;
        if(k == 0)
            printf("0");
        for(i = 0; i < k+cz ; ++i){
            if(d[i] != '0')
                l = 1;
            if(l != 0)
                printf("%c", d[i]);

            if(count == 0 && i != k+cz-1 || count == -3 && i != k+cz-1){
                printf(",");
                count = 3;
            }

            if(l)
                count--;
        }

        printf(".%d%d\n", (c/10)%10, c%10);
    }

return 0;
}
