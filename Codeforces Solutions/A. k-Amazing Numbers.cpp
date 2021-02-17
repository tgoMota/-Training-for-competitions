//A. k-Amazing Numbers
//https://codeforces.com/problemset/problem/1416/A
#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
#define ooLL 0x3f3f3f3f3f3f3f3f
#define fastio() ios_base::sync_with_stdio(false); cin.tie(0)
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
vector<int> v;
vector<vector<int>> idx;
vector<int> ans;
int main(){
    fastio();
    int t;
    cin >> t;
    for(int ti = 1; ti <= t ; ++ti){
        int n;
        cin >> n;
        v.resize(n+1);
        idx.assign(n+1, vector<int>());
        for(int i = 1; i <= n ; ++i){
          cin >> v[i];
          idx[v[i]].push_back(i);
        }
        ans.assign(n+5, oo);
        for(int i = 1; i <= n ; ++i){
          int best = 0, last = 0;
          for(int p : idx[i]){
            best = max(best, p-last);
            last = p;
          }
          best = max(best, n-last+1);
          ans[best] = min(ans[best], i);
        }
        for(int i = 1; i <= n ; ++i){
          ans[i] = min(ans[i], ans[i-1]);
          cout << (ans[i] == oo ? -1 : ans[i]) << " ";
        }
        cout << '\n';
    }
    return 0;
}
