//https://codeforces.com/contest/1496/problem/B
//Codeforces | B. Max and Mex
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
set<int> s;
int main(){
    fastio();
    int t;
    cin >> t;
    for(int ti = 1; ti <= t ; ++ti){
        s.clear();
        int n, k, mx = 0;
        cin >> n >> k;
        for(int i = 0; i < n ; ++i){
          int a;
          cin >> a;
          s.insert(a);
          mx = max(mx, a);
        }

        auto it = s.begin();
        int krest = k, ans = 0, nextMex = 0;
        while(krest){
         for(; it != s.end() ; ++it){
            int val = *it;
            if(nextMex != val) break;
            nextMex++;
          }
          mx = max(mx, nextMex);
          if(mx == nextMex){
            ans = (int)s.size() + krest;
            break;
          }
          int m = (nextMex + mx-1)/2+1;
          if(m != nextMex && m <= mx){
            s.insert(m);
            ans = (int)s.size();
            break;
          }
          s.insert(m);
          krest--;
        }
        if(!krest) ans = (int)s.size();
        cout << ans << '\n';
    }
    return 0;
}