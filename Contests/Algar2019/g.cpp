#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    while(n--){
       int a, b, c;
       scanf("%d%d%d", &a, &b, &c);
       printf("Teste: %d %d %d\n", a, b, c);
       int mxa = max({a,c});
       int mxb = max({b,c});
       int i, j;
       int ans = 0;
       int tot = (mxa+1) * (mxb+1);
       int maxab = max(mxa, mxb);
       for(i = mxa, j = mxb; ~i && ~j ;){
           if(i+j <= c) {
               ans = (i+1)*(j+1);
               printf("i = %d e j = %d\n", i, j);
               break;
           }else{
               if(maxab == mxa) --i;
               else --j;
            } 
       }

       printf("%d/%d\n", ans, tot);
    }

    return 0;
}