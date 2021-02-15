//N. Elongated Matrix
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
int n, m;

int main(){
  fastio();
  cin >> n >> m;    
  vector<vector<int>> grid(n, vector<int>(m));
  for(vector<int>& a : grid){
    for(int& x : a) cin >> x;
  }

  vector<vector<int>> dist(n, vector<int>(n, oo));
  for(int i = 0; i < n ; ++i){
    for(int j = 0; j < n ; ++j){
      for(int w = 0; w < m ; ++w){
        dist[i][j] = min(dist[i][j], abs(grid[i][w] - grid[j][w]));
      }
    }
  }

  vector<vector<int>> dist2(n, vector<int>(n, oo));
  for(int i = 0; i < n ; ++i){
    for(int j = 0; j < n ; ++j){
      for(int w = 0; w < m-1 ; ++w){
        dist2[i][j] = min(dist2[i][j], abs(grid[i][w] - grid[j][w+1]));
      }
    }
  }

  int ans = 0, fullmask = (1<<n)-1;
  for(int row = 0; row < n ; ++row){
    vector<vector<int>> dp(fullmask+1, vector<int>(n, 0));
    dp[1<<row][row] = oo;
    for(int mask = 1; mask < fullmask ; ++mask){
      for(int prev_row = 0; prev_row < n ; ++prev_row){
        if(((1<<row) & mask) && ((1<<prev_row) & mask)){
          for(int new_row = 0; new_row < n ; ++new_row){
            if((1<<new_row) & mask) continue;
            const int new_state = mask | (1<<new_row);
            const int new_cost = min(dist[prev_row][new_row], dp[mask][prev_row]);
            dp[new_state][new_row] = max(dp[new_state][new_row], new_cost);
          }
        }
      }
    }
    for(int i = 0; i < n ; ++i){
      ans = max(ans, min(dp[fullmask][i], dist2[row][i]));
    }
  }

  cout << ans << '\n';
 
  
  return 0;
}

