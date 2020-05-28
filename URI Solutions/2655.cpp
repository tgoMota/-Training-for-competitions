//https://www.urionlinejudge.com.br/judge/pt/problems/view/2655
//URI | 2655 Trilha Perigosa
#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
#define ooLL 0x3f3f3f3f3f3f3f3f
#define fastio() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
const int mod = 1e9+7;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> ii;
int n, q, m;
const int maxN = 100005;
ll t[4*maxN];
int v[maxN];

void build(int i, int l, int r){
    if(l == r) t[i] = (1LL << v[l]);
    else{
        int m = (l + r)>>1;
        build(2*i, l, m);
        build(2*i+1, m+1, r);
        t[i] = t[2*i] | t[2*i+1];
    }
}

ll query(int i, int l, int r, int ql, int qr){
    if(ql <= l && qr >= r) return t[i];
    if(ql > r || qr < l) return 0LL;
    int m = (l+r)>>1;
    return query(2*i, l, m, ql, qr) | query(2*i+1, m+1, r, ql, qr);
}

void update(int i, int l, int r, int p, int x){
    if(l == r) t[i] = (1LL << x);
    else{
        int m = (l+r)>>1;
        if(p <= m) update(2*i, l, m, p, x);
        else update(2*i+1, m+1, r, p, x);
        t[i] = t[2*i] | t[2*i+1];
    }
}


int main(){
    fastio();
    cin >> n >> q >> m;
    for(int i = 0; i < n ; ++i) cin >> v[i];
    build(1, 0, n-1);
    for(int i = 0; i < q ; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        if(a == 1) cout << __builtin_popcountll(query(1, 0, n-1, b-1, c-1)) << '\n';
        else update(1, 0, n-1, b-1, c);
    }
    return 0;
}