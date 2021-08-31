//https://cses.fi/problemset/task/1193/
//Labyrinth
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

int dx[] = {1,-1,0,0}, dy[] = {0,0,1,-1};
vector<vector<bool>> vst;
vector<vector<pair<char,ii>>> parent;
ii start, endP;
int n, m;
string dir = "DURL";
int bfs(int i, int j){
  queue<pair<int,ii>> q;
  q.push({0,{i,j}});
  vst[i][j] = true;
  while(!q.empty()){
    auto t = q.front();
    q.pop();
    if(t.second.first == endP.first && t.second.second == endP.second) return t.first;
    for(int d = 0; d < 4 ; ++d){
      int new_x = t.second.first + dx[d];
      int new_y = t.second.second + dy[d];
      if(new_x < 0 || new_x >= n || new_y < 0 || new_y >= m || grid[new_x][new_y] == '#' || vst[new_x][new_y]) continue;
      vst[new_x][new_y] = true;
      //trace(dir[d], t.second.first, t.second.second, new_x, new_y, dx[d], dy[d]);
      parent[new_x][new_y] = {dir[d], {t.second.first, t.second.second}};
      q.push({t.first+1, {new_x, new_y}});
    }
  }
  return -1;
}

void print(int i, int j){
  if(i == start.first && j == start.second) return;
  print(parent[i][j].second.first, parent[i][j].second.second);
  cout << parent[i][j].first;
}

int main(){
    fastio();
    cin >> n >> m;

    for(int i= 0; i < n ; ++i){
      string line;
      cin >> line;
      grid.push_back(line);
      for(int j = 0; j < m ; ++j){
        if(line[j] == 'A') start = {i,j};
        if(line[j] == 'B') endP = {i,j};
      }
    }
    vst.assign(n, vector<bool>(m, false));
    parent.assign(n, vector<pair<char,ii>>(m, {'R',{0,0}}));
    parent[start.first][start.second] = {'R', {start.first, start.second}};
    int ans = bfs(start.first, start.second);
    if(ans == -1){
      cout << "NO\n";
      return 0;
    }

    cout << "YES\n";
    cout << ans << '\n';
    print(endP.first, endP.second);
    cout << '\n';
    return 0;
}

