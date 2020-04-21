#include <stdio.h>

int mdc(int a, int b){

   int q = 0;
   int r = 0;

   do {

      q = b / a;
      r = b % a;
      b = a;
      if (r) a = r;

   } while (r != 0);

   return a;
}

int main(){

    int n, fig1, fig2;
    scanf("%d", &n);
    while(n>0){
        scanf("%d%d", &fig1, &fig2);
        if(fig2 > fig1){
            fig1 += fig2;
            fig2 = fig1 - fig2;
            fig1 -= fig2;
        }
        printf("%d\n", mdc(fig1, fig2));
        --n;
    }

return 0;
}
