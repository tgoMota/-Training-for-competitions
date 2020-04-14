#include <bits/stdc++.h>
using namespace std;

bool can(int a, int b, int rangea, int rangeb){
    if(rangea == rangeb) return false;
    int ans = a | b;
    return ((ans & a) == a) && ((ans & b) == b);
}

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    int v[m][3];
    for(int i = 0; i < m ; ++i)
        for(int j = 0; j < 3 ; ++j) cin >> v[i][j];
    bool ans = 1;
    for(int i = 0; i < m-1 ; ++i){
        ans = can(v[i][2], v[i+1][2], v[i][1], v[i+1][1]);
        if(!ans) break;
    }

    printf("%s\n", ans? "SIM" : "NAO");

    return 0;
}