//https://www.urionlinejudge.com.br/judge/pt/problems/view/1599
//URI 1599 - Picos do Átlas
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
//CHECK THE LIMITS, PLEASE
int n, m;
vector<vector<int>> grid;
int main(){
    while(scanf("%d%d", &n, &m) != EOF){
      grid.assign(n+1, vector<int>(m+1));
      vector<ii> ans;
      for(int i = 1; i <= n ; ++i){
        for(int j = 1; j <= m ; ++j){
          cin >> grid[i][j];
        }
      }

      for(int i = 1; i <= n ; ++i){
        for(int j = 1; j <= m ; ++j){
          bool a = (j == 1 || grid[i][j] > grid[i][j-1]);
          a&= (j == m || grid[i][j] > grid[i][j+1]); 
          a&= (i == 1 || grid[i][j] > grid[i-1][j]); 
          a&= (i == n || grid[i][j] > grid[i+1][j]);

          a&= (i == 1 || j == 1 || grid[i][j] > grid[i-1][j-1]);
          a&= (i == n || j == 1 || grid[i][j] > grid[i+1][j-1]);
          a&= (i == n || j == m || grid[i][j] > grid[i+1][j+1]);
          a&= (i == 1 || j == m || grid[i][j] > grid[i-1][j+1]);
          if(a) ans.push_back({i,j});
        }
      }
      if(ans.empty()){
        cout << -1 << "\n\n";
        continue;
      }
      sort(ans.begin(), ans.end(), [&](ii& a, ii& b){
        if(a.first == b.first) return a.second < b.second;
        return a.first < b.first;
      });
      for(ii& x : ans) cout << x.first << " " << x.second << '\n';
      cout << '\n';
    }
    return 0;
}
