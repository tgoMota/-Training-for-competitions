//https://www.urionlinejudge.com.br/judge/pt/problems/view/2552
//URI 2552 - PãodeQuejoSweeper
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
    int n, m;
    while(cin >> n >> m){
      vector<vector<int>> grid(n,vector<int>(m, 0));
      vector<vector<int>> ans(n, vector<int>(m, 0));
      for(int i = 0; i < n ; ++i){
        for(int j = 0; j < m ; ++j){
          cin >> grid[i][j];
          ans[i][j] = grid[i][j];
        }
      }

      for(int i = 0; i < n ; ++i){
        for(int j = 0; j < m ; ++j){
          if(grid[i][j] == 0) continue;
          if(i > 0) ans[i-1][j]++;
          if(i < n-1) ans[i+1][j]++;
          if(j > 0) ans[i][j-1]++;
          if(j < m-1) ans[i][j+1]++;
        }
      }

      for(int i = 0; i < n ; ++i){
        for(int j = 0; j < m ; ++j){
          if(grid[i][j]) ans[i][j] = 9;
          printf("%d", ans[i][j]);
        }
        printf("\n");
      }
    }
    return 0;
}

