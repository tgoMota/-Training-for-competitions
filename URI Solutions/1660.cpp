//https://www.urionlinejudge.com.br/judge/pt/problems/view/1660
//URI 1660 - Flavius Josephus Está de Volta
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//CHECK THE CONSTRAINTS, PLEASE
ll a, b, n;
int f(ll x){
  return ( (((a*x)%n)*x)%n + b)%n;
}
int main(){
    fastio();
    while(cin >> n && n){
      cin >> a >> b;
      unordered_map<int,int> cnt;
      int x = 0, deads = 0;
      while(1){
        int r = ++cnt[x];
        if(r == 2) deads++;
        if(r > 2) break;
        x = f(x);
      }
      cout << (n - (ll)deads) << '\n';
    }
    return 0;
}
