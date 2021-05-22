//https://codeforces.com/contest/152/problem/C
//C. Pocket Book
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
    int n, m;
    cin >> n >> m;
    vector<string> v(n);
    for(int i = 0; i < n ; ++i){
      cin >> v[i];
    }
    ll ans = 1LL;
    for(int j = 0; j < m ; ++j){
      set<char> s;
      for(int i = 0; i < n ; ++i){
        if(s.find(v[i][j])!= s.end()) continue;
        s.insert(v[i][j]);
      }
      ans*=(ll)s.size();
      ans%=mod;
    }

    cout << ans << '\n';
    return 0;
}
