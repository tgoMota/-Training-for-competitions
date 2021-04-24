//https://codeforces.com/contest/1514/problem/C
//C. Product 1 Modulo N
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
    set<int> ans;
    ll prod = 1LL;
    for(int i = 1; i < n ; ++i){
      if(__gcd(i, n) == 1) ans.insert(i), prod = (prod*i)%n;
    }
    if(prod != 1) ans.erase(prod);
    cout << (int)ans.size() << '\n';
    for(int x : ans) cout << x << ' ';
    cout << '\n';
    return 0;
}
