//https://www.urionlinejudge.com.br/judge/pt/problems/view/2495
//URI 2495 - Onde Está Minha Caneta?
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
    while(cin >> n){
      vector<int> v(n-1);
      for(int& x : v) cin >> x;
      sort(v.begin(), v.end());
      int lo = 0, hi = n-1;
      while(lo < hi){
        int mid = (lo + hi) >> 1;
        if(v[mid] > mid+1) hi = mid;
        else lo = mid+1;
      }

      cout << lo+1 << '\n';
    }
    return 0;
}

