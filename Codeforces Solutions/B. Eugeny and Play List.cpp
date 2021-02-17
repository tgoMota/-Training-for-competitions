//B. Eugeny and Play List
//https://codeforces.com/problemset/problem/302/B
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
vector<ii> v;
int main(){
    int n, m;
    cin >> n >> m;
    v.resize(n);
    for(ii& x : v) cin >> x.first >> x.second;
    vector<ll> pref(n+1, 0);
    pref[0] = v[0].first*v[0].second;
    for(int i = 1; i < n ; ++i) pref[i] += pref[i-1] + v[i].first*1LL*v[i].second;
    auto getSum = [&](int r){
      return pref[r];
    };
    while(m--){
      int q;
      cin >> q;
      int lo = 0, hi = n;
      while(lo < hi){
        int mid = (lo + hi)/2;
        ll x = getSum(mid);
        if(x >= q) hi = mid;
        else lo = mid+1;
      }
      if(lo == n) lo--;
      cout << lo+1 << '\n';
    }
    return 0;
}
