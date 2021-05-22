//https://codeforces.com/problemset/problem/1166/A
//A. Silent Classroom
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
    cin >> n;
    unordered_map<char,int> cnt;
    for(int i = 0; i < n ; ++i){
      string x;
      cin >> x;
      cnt[x[0]]++;
    }

    ll ans = 0LL;
    for(auto x : cnt){ 
      ll c = x.second/2;
      if(c*2 == x.second) ans+= c*(c-1);
      else ans+=c*c;
    }

    cout << ans << '\n';
    return 0;
}
