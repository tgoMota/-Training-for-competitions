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
    //fastio();
    int n, m;
    cin >> n >> n;
    vector<ii> v(n);
    for(int i = 0; i < n ; ++i){
      cin >> v[i].first;
      v[i].second = i;
    }
    sort(v.begin(), v.end(), [&](ii& a, ii& b){
      return a.first < b.first;
    });

    for(int i = 0; i < m ; ++i){
      int k, x;
      cin >> k >> x;
      int lo = 0, hi = n;
      while(lo < hi){
        int mid = (lo + hi) >> 1;
        if(v[mid].first >= x) hi = mid;
        else lo = mid+1;
      }
      if(lo == n || v[lo].first != x || lo + k-1 >= n || v[lo+k-1].first != x){
        cout << 0 << '\n';
        continue;
      }

      cout << v[lo+k-1].second+1 << '\n';
    }
    return 0;
}

