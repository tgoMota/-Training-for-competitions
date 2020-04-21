#include <bits/stdc++.h>
using namespace std;

int v[100001], lis[100001], n, t;

int _lis(){
    lis[0] = 1;
    for(int i = 1; i <= n ; ++i){
        lis[i] = 1;
        for(int j = 0; j < i ; ++j){
            if(v[i] <= v[j] && lis[i] < lis[j] + 1)
                lis[i] = lis[j] + 1;
        }
    }
    return *max_element(lis, lis+n+1);
}

int main(){

    while(1){
        n = 0;
        while(1){
            scanf("%d", &v[n]);
            if(v[n] == -1){
                if(n == 0) exit(0);
                n--;
                break;
            }
            n++;
        }
        if(t) printf("\n");
        printf("Test #%d:\n  maximum possible interceptions: %d\n", ++t, _lis());
    }

    return 0;
}