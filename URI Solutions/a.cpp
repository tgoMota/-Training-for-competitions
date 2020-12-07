//https://www.urionlinejudge.com.br/judge/pt/problems/view/1058
//URI1058 - Zonas de Ataque Independentes
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
string v;
int n;
int memo[45][45];
int solve(int i, int j){
  if(i > j) return memo[i][j] = 1;;
  int& ans = memo[i][j];
  if(ans != -1) return ans;
  ans = 0;
  int nwred = (v[i] =='R') + (v[i+1] == 'R') + (v[j] == 'R');
  if(nwred <= 1) ans += solve(i+2, j-1);
  nwred = (v[i] =='R') + (v[j] == 'R') + (v[j-1] == 'R');
  if(nwred <= 1) ans += solve(i+1, j-2);

  nwred = (v[i] =='R') + (v[i+1] == 'R') + (v[i+2] == 'R');
  if(nwred <= 1) ans += solve(i+3, j);

  nwred = (v[j] =='R') + (v[j-1] == 'R') + (v[j-2] == 'R');
  if(nwred <= 1) ans += solve(i, j-3);

  return ans;
}

int main(){
    int t;
    cin >> t;
    for(int ti = 1; ti <= t ; ++ti){
      cin >> n;
      cin >> v;
      memset(memo, -1, sizeof(memo));
      int ans = solve(0, n-1);
      cout << "Case " << ti << ": " << ans << '\n'; 
    }
    return 0;
}