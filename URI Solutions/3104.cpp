//https://www.urionlinejudge.com.br/judge/pt/problems/view/3104
//URI 3104 - Resto 2.0
#include <bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
typedef long long ll;

void solve(string num, ll m) {
   ll mod = 0;
   for (int i = 0; i < num.size(); i++) {
      int digit = num[i] - '0';
      mod = mod * 10 + digit;
      mod %= m;
   }
   cout << mod << '\n';
}
int main(){
    fastio();
    string a;
    cin >> a;
    ll b;
    cin >> b;
    solve(a,b);
    return 0;
}