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
int dx[] = {0,0,1,-1}, dy[] = {1,-1,0,0};
int n, m;
vector<string> grid;

void dfs(int i, int j){
  if(grid[i][j] == 'o') return;
  grid[i][j] = 'o';
  for(int x = 0; x < 4 ; ++x){
    int px = dx[x] + i;
    int py = dy[x] + j;
    if(px < 0 || px >= n || py < 0 || py >= m) continue;
    dfs(px, py);
  }
}

int main(){
    fastio();
    cin >> n >> m;
    grid.resize(n);
    for(string& x : grid) cin >> x;
    int ans = 0;
    for(int i = 0; i < n ; ++i){
      for(int j = 0; j < m ; ++j){
        if(grid[i][j] == 'o') continue;
        dfs(i,j);
        ans++;
      }
    }
    cout << ans << '\n';
    return 0;
}

