#include <bits/stdc++.h>
using namespace std;
const int M = 1e5+5, oo = 1e9+3;
int t[4*M], N, Q;
vector<int> a;

void build(int i, int l, int r){
    if(l == r) t[i] = a[l];
    else{
        int m = l + (r-l)/2;
        build(2*i, l, m);
        build(2*i+1, m+1, r);
        t[i] = min(t[2*i], t[2*i+1]);
    }
}

int query(int i, int l, int r, int ql, int qr){
    if(ql <= l && qr >= r) return t[i];
    if(ql > r || qr < l) return oo;
    int m = l + (r-l)/2;
    return min(query(2*i, l, m, ql, qr), query(2*i+1, m+1, r, ql, qr));
}


int main(){
    int ti;
    scanf("%d", &ti);
    for(int i = 1; i <= ti ; ++i){
        scanf("%d%d", &N, &Q);
        a.assign(N, 0);
        for(int& x : a) scanf("%d", &x);
        build(1, 0, N-1);
        printf("Scenario #%d:\n", i);
        int ql, qr;
        for(int j = 1; j <= Q ; ++j){
            cin >> ql >> qr;
            printf("%d\n", query(1, 0, N-1, ql-1, qr-1));
        }
    }
    return 0;
}