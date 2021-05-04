//https://www.urionlinejudge.com.br/judge/pt/problems/view/1660
//URI 1660 - Flavius Josephus Está de Volta
#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
#define ooLL 0x3f3f3f3f3f3f3f3f
#define fastio() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define LOCAL
#ifdef LOCAL
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
#else
#define trace(...) 42
#endif
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
  cerr << name << ": " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << ": " << arg1 << " |";
  __f(comma + 1, args...);
}
const int mod = 1e9+7;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
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
