//https://codeforces.com/problemset/problem/1512/D
//D. Corrupted Array
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
    int t;
    cin >> t;
    for(int ti = 1; ti <= t ; ++ti){
        int n;
        cin >> n;
        vector<ll> v(n+2);
        ll sum = 0LL;
        for(ll& x : v) cin >> x, sum+=x;
        multiset<ll> ms(v.begin(), v.end());
        bool ok = false;
        for(int i = 0; i < n+2 && !ok ; ++i){
          ll new_sum = sum-v[i];
          if(new_sum % 2LL) continue;
          ms.erase(ms.find(v[i]));
          if(ms.find(new_sum/2LL) != ms.end()){
            ok = true;
            bool removed = false;
            for(int j = 0; j < n+2 ; ++j){
              if(j == i) continue;
              if(v[j] == new_sum/2LL && !removed) {
                removed = true;
                continue;
              }
              cout << v[j] << ' ';
            }
            cout << '\n';
          }
          ms.insert(v[i]);
        }
        if(!ok) cout << -1 << '\n';
    }
    return 0;
}
