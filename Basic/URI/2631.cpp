//https://www.urionlinejudge.com.br/judge/pt/problems/view/2631
//URI 2631 - Formando Duplas
#include <bits/stdc++.h>
using namespace std;
int n, m, q, t;
vector<int> dad;

int find(int x){
    if(dad[x] == x) return x;
    return dad[x] = find(dad[x]);
}

void unionS(int a, int b){
    int x = find(a);
    int y = find(b);
    if(x != y) dad[y] = x;
}

bool sameSet(int a, int b){ return find(a) == find(b);}

int main(){

    while(scanf("%d%d%d", &n, &m, &q) != EOF){
        if(t++) printf("\n");
        dad.assign(n+1, 0);
        for(int i = 1; i <= n ; ++i) dad[i] = i;
        int a, b;
        for(int i = 0; i < m ; ++i){
            scanf("%d%d", &a, &b);
            unionS(a,b);
        }

        for(int i = 0; i < q ; ++i){
            scanf("%d%d", &a, &b);
            if(sameSet(a,b)) printf("S\n");
            else printf("N\n");
        }
    }

    return 0;
}