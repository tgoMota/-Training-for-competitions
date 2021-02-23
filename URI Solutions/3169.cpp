//https://www.urionlinejudge.com.br/judge/pt/problems/view/3169
//URI 3169 - Batendo em Retirada
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
const int MAXN = 105;
char grid[MAXN][MAXN];

int dist[MAXN][MAXN];
int dist2[15][15];

int dx[] = {1,-1,0,0}, dy[] = {0,0,1,-1};

map<ii,int> mpFriend;
map<ii,int> mpPortal;

void bfs(int pi, int pj, const int n){
  const int idPortal = mpPortal[{pi,pj}];
  memset(dist, -1, sizeof(dist));
  queue<ii> q;
  q.push({pi,pj});
  dist[pi][pj] = 0;
  while(!q.empty()){
    auto x = q.front();
    q.pop();
    for(int i = 0; i < 4 ; ++i){
      int ax = x.first + dx[i];
      int ay = x.second + dy[i];
      if(ax < 0 || ax >= n || ay < 0 || ay >= n) continue;
      if(grid[ax][ay] == '#') continue;
      if(dist[ax][ay] != -1) continue;
      dist[ax][ay] = dist[x.first][x.second]+1;
      if(grid[ax][ay] == 'G'){
        const int idFriend = mpFriend[{ax,ay}];
        dist2[idPortal][idFriend] = dist[ax][ay];
      }
      q.push({ax,ay});
    }
  }
}

int solve(int idP, int mask, int maxOnPath, const int NP){
  if(idP >= NP) return mask == 0 ? maxOnPath : oo;
  if(mask == 0) return oo;
  int ans = oo;
  for(int i = 0; i < NP ; ++i){
    if(dist2[idP][i] == -1) continue;
    if(mask & (1<<i)){
      ans = min(ans,solve(idP+1, mask ^ (1<<i), max(maxOnPath, dist2[idP][i]), NP));
    }
  }
  return ans;
}

int main(){
    int t;
    scanf("%d", &t);
    for(int ti = 1; ti <= t ; ++ti){
        memset(grid, 0, sizeof(grid));
        mpFriend.clear();
        mpPortal.clear();
        int n, p;
        scanf("%d%d", &n, &p);
        int cntPortal = 0, cntFriend = 0;
        for(int i = 0; i < n ; ++i){
          scanf("%s", &grid[i]);
          for(int j = 0; j < n ; ++j){
            if(grid[i][j] == 'X') mpPortal[{i,j}] = cntPortal++;
            else if(grid[i][j] == 'G') mpFriend[{i,j}] = cntFriend++;
          }
        }
        memset(dist2, -1, sizeof(dist2));
        for(auto x : mpPortal){
          auto y = x.first;
          bfs(y.first, y.second, n);
        }
        
         int ans = solve(0,(1<<cntPortal)-1, 0, cntPortal);
         printf("%d\n", ans == oo ? -1 : ans);
    }
    return 0;
}