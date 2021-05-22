//https://codeforces.com/contest/978/problem/E
//E. Bus Video System
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
int main(){
    fastio();
    ll n, m;
    cin >> n >> m;
    ll minx = oo, maxx = -oo, sum = 0LL;
    for(int i = 0; i < n ; ++i){
      int x;
      cin >> x;
      sum+=x;
      minx = min(minx, sum);
      maxx = max(maxx, sum);
    }
    minx = min(minx, 0LL);
    maxx = max(maxx, 0LL);
    ll ans = max(m-maxx+minx+1, 0LL);
    cout << ans << '\n';
    return 0;
}
