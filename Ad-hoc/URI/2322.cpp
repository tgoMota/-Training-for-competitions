//https://www.urionlinejudge.com.br/judge/pt/runs/code/16221508
//URI - Peça Perdida
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    int v[n], i;
    for(int i = 0; i < n-1 ; ++i) scanf("%d", &v[i]);
    sort(v, v+n-1);
    for(int i = 0; i < n-1 ; ++i){
        if(v[i] != i+1){
            printf("%d\n", i+1);
            exit(0);
        }
    }
    printf("%d\n", n);

    return 0;
}