//https://codeforces.com/problemset/problem/776/C
//C. Molly's Chemicals
#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
#define ooLL 0x3f3f3f3f3f3f3f3f
#define fastio() ios_base::sync_with_stdio(false); cin.tie(0)
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
vector<ll> v;
int main(){
    ll max_x = 0LL;
    int n, k;
    cin >> n >> k;
    v.resize(n);
    for(ll& x : v) cin >> x;
    ll ans = 0LL, x = 1LL;
    while(x <= (ll)1e14){
      map<ll,ll> mp;
      ll sum = 0LL;
      for(int i = 0; i < n ; ++i) {
        sum += v[i];
        if(sum == x) ans++;
        ans += mp[sum-x];
        mp[sum]++;
      }
      x*=k;
      if(x == 1) break;
    }
    cout << ans << '\n';
    return 0;
}
