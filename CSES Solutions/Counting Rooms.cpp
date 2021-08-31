//Counting Rooms
//https://cses.fi/problemset/task/1192
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
typedef pair<int,int> ii;
//CHECK THE CONSTRAINTS, PLEASE
vector<string> grid;
vector<vector<bool>> vst;
int dx[] = {1,-1,0,0}, dy[] = {0,0,1,-1};
void dfs(int i, int j, const int n, const int m){
  if(grid[i][j] == '#') return;
  vst[i][j] = true;
  for(int d = 0; d < 4 ; ++d){
    int new_x = i+dx[d];
    int new_y = j+dy[d];
    if(new_x < 0 || new_x >= n || new_y < 0 || new_y >= m || vst[new_x][new_y]) continue;
    dfs(new_x, new_y, n, m);
  }
}
int main(){
    fastio();
    int n, m;
    cin >> n >> m;
    string s;
    for(int i = 0; i < n ; ++i){
      string line;
      cin >> line;
      grid.push_back(line);
    }

    vst.assign(n+1, vector<bool>(m+1, false));
    int ans = 0;
    for(int i = 0; i < n ; ++i){
      for(int j = 0; j < m ; ++j){
        if(vst[i][j] || grid[i][j] == '#') continue;
        ans++;
        dfs(i,j, n, m);
      }
    }

    cout << ans << '\n';

    return 0;
}

