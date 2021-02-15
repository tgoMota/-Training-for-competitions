//O. Hard Process
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
vector<int> pref;
int getSum(int l, int r){
  return pref[r] - (l > 0 ? pref[l-1] : 0);
}
int main(){
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for(int& x : v) cin >> x;
 
    pref.resize(n);
    pref[0] = (v[0] == 0);
    for(int i = 1; i < n ; ++i) pref[i] += pref[i-1] + (v[i] == 0);

    pair<int,ii> best = {0,{0,0}};
    for(int i = 0; i < n ; ++i){
      int lo = 0, hi = n;
      while(lo < hi){
        int mid = (lo + hi) >> 1;
        if(getSum(i,mid) > k) hi = mid;
        else lo = mid+1;
      }
      best = max(best, {lo-i, {i,lo}});
    }
    cout << best.first << '\n';
    for(int i = 0; i < n ; ++i){
      if(i >= best.second.first && i < best.second.second) v[i] = 1;
      cout << v[i] << " ";
    }
    cout << '\n';
    return 0;
}

