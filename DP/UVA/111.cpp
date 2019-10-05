#include <bits/stdc++.h>
using namespace std;

int n, v[3][21], lis[21], memo[21];

int _lis(int n){
    lis[1] = 1;
    for(int i = 2; i <= n ; ++i){
        lis[i] = 1;
        for(int j = 1 ; j < i ; ++j){
            if(v[1][i] > v[1][j] && lis[i] < lis[j] + 1 && memo[v[1][i]] > memo[v[1][j]]) 
                lis[i] = lis[j] + 1;
        }
    }
    return *max_element(lis, lis+n);
}

int main(){
    while(scanf("%d", &n) == 1){
        for(int i = 1; i <= n ; ++i) {
            cin >> v[0][i];
            memo[v[0][i]] = i;
        }
        while(scanf("%d", &v[1][1]) == 1){
            for(int i = 2; i <= n ; ++i) scanf("%d", &v[1][i]);
            printf("\nLis: %d\n", _lis(n));
            for(int i = 1; i <= n ; ++i){
                v[0][i] = v[1][i];
                memo[v[0][i]] = i;
            }
        }
    }
    return 0;
}