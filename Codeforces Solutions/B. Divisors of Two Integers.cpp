//https://codeforces.com/contest/1108/problem/B
//B. Divisors of Two Integers
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
    int n;
    cin  >> n;
    map<int,int> cnt;
    int mx = -oo, x;
    for(int i = 0; i < n ; ++i) {
      cin >> x;
      cnt[x]++;
      mx = max(mx, x);
    }
    int secondMx = -1, secondAns = -1;
    bool has = false;
    for(auto x : cnt){
      if(x.second == 1) {
        if(mx%x.first) secondMx = max(secondMx, x.first);
        has = true;
      }else secondAns = x.first;
    }
    cout << mx << ' ';
    if(!has) cout << mx << '\n';
    else if(secondMx != -1) cout << secondMx << '\n';
    else cout << secondAns << '\n';
    return 0;
}
