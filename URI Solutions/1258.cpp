//https://www.urionlinejudge.com.br/judge/pt/problems/view/1258
//URI 1258 - Camisas
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
//CHECK THE LIMITS, PLEASE
vector<vector<string>> v;

int main(){
    int t, idx = 0;
    fastio();
    while(cin >> t && t){
      v.clear();
      if(idx++ != 0) cout << '\n';
      for(int ti = 1; ti <= t ; ++ti){
          cin.ignore();
          string name;
          getline(cin, name);
          string color, size;
          cin >> color >> size;
          v.push_back({color, size, name});
         // trace(color, size, name);
      }
      sort(v.begin(), v.end(), [](vector<string>& a, vector<string>& b){
        if(a[0] != b[0]) return a[0] < b[0];
        if(a[1] != b[1]) return a[1] > b[1];
        return a[2] < b[2];
      });

      for(vector<string>& x : v){
        cout << x[0] << ' ' << x[1] << ' ' << x[2] << '\n';
      }
    }
    return 0;
}
