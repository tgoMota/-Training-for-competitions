//https://onlinejudge.org/external/120/12086.pdf
//UVA 12086 Potentiometers
#include <bits/stdc++.h>
using namespace std;
vector<int> fen;

void add(int idx, int val, const int N){
    while(idx && idx <= N){
        fen[idx] += val;
        idx += idx & -idx;
    }
}

int query(int idx, const int N){
    int sum = 0;
    while(idx && idx <= N){
        sum += fen[idx];
        idx -= idx & -idx;
    }
    return sum;
}

int query(int l, int r, const int N){
    return query(r, N)-query(l-1, N);
}

int main(){
    int n, t = 0;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(cin >> n && n){
        if(t) cout << '\n';
        fen.assign(n+1, 0);
        for(int i = 1; i <= n ; ++i) {
            int a;
            cin >> a;
            add(i,a,n);
        }
        cout << "Case " << ++t << ":\n";
        string str;
        while(cin >> str && str != "END"){
            int a, b;
            cin >> a >> b;
            if(str == "M") cout << query(a,b,n) << '\n';
            else add(a, b-query(a,a,n), n); 
        }
    }
    return 0;
}