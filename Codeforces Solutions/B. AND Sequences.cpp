//https://codeforces.com/problemset/problem/1513/B
//B. AND Sequences 
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
ll fat(int x){
  if(x <= 1) return 1;
  return (x*(fat(x-1)%mod))%mod;
}
int main(){
    fastio();
    int t;
    cin >> t;
    for(int ti = 1; ti <= t ; ++ti){
        int n;
        cin >> n;
        vector<int> v(n);
        int mx = oo;
        for(int& x : v) cin >> x, mx = min(mx, x);
        ll cnt = 0LL;
        for(int x : v) if(x == mx) cnt++;
        for(int x : v) if((mx&x) != mx) cnt = 1LL;
        cout << (((cnt*(cnt-1))%mod*(fat(n-2)))%mod) << '\n';
    }
    return 0;
}

