//https://codeforces.com/contest/1486/problem/C1
//C1. Guessing the Greatest (hard version)
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
int query(int l, int r){
  cout << "? " << l << " " << r << endl;
  int ans;
  cin >> ans;
  return ans;
}
 
int main(){
    int n;
    cin >> n;
    int s_mx = query(1,n), ans;
    if(s_mx != 1 && query(1,s_mx) == s_mx){
      int lo = 1, hi = s_mx;
      while(lo < hi){
        int mid = (lo + hi) >> 1;
        if(query(mid, s_mx) != s_mx) hi = mid;
        else lo = mid+1;
      }
      ans = lo - (lo > 1);
    }else{ //1 2 3
      int lo = s_mx+1, hi = n;
      while(lo < hi){
        int mid = (lo + hi) >> 1;
        if(query(s_mx, mid) != s_mx) lo = mid+1;
        else hi = mid;
      }
      ans = lo;
    }
    cout << "! " << ans << endl;
    return 0;
}