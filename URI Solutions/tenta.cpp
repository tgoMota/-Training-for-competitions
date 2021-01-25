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
int N, M, P;
vector<string> grid;
vector<map<ii,int>> memo;
map<ii,int> counterP;
bool vst[105][105];

int dx[] = {1,1,-1,-1,2,2,-2,-2}, dy[] = {2,-2,2,-2,1,-1,1,-1};
int solve(int i, int j, int mask){
 // trace(i,j,mask);
  if(vst[i][j]) return oo;
  if(mask == 0) return 0;
  if(i >= N  || i < 0 || j >= M || j < 0) return oo;
  map<ii,int>& pos = memo[mask];
  if(pos.find({i,j}) != pos.end()) return pos[{i,j}];
  int ans = oo;
  for(int dir = 0; dir < 4 ; ++dir){
    int new_x = dx[dir]+i;
    int new_y = dy[dir]+j;
    if(new_x < 0 || new_x >= N || new_y < 0 || new_y >= M) continue;
    if(grid[new_x][new_y] == '#') continue;
    int counter = -1;
    int new_mask = mask;
    if(counterP.find({new_x, new_y}) != counterP.end()){
      counter = counterP[{new_x, new_y}];
      if(new_mask & (1<<counter)) {
        new_mask-= (1<<counter);
        //memset(vst, false, sizeof(vst));
      }
    }
    vst[i][j] = true;
    ans = min(ans, 1+solve(new_x, new_y, new_mask));
    vst[i][j] = false;
  }
  pos[{i,j}] = ans;
  return ans;
}

int main(){
    while(scanf("%d%d%d", &N, &M, &P) && N+M+P){
      grid.clear();
      counterP.clear();
      ii posIni;
      int countP = 0;
      for(int i = 0; i < N ; ++i){
        string line;
        cin >> line;
        grid.push_back(line);
        for(int j = 0; j < N ; ++j){
          if(line[j] == 'C') posIni = {i,j};
          if(line[j] == 'P') counterP[{i,j}] = countP++;
        }
      }
      int mask = (1<<P);
      memo.assign(mask, map<ii,int>());
      memset(vst, false, sizeof(vst));
      printf("%d\n", solve(posIni.first, posIni.second, mask-1));
    }
    return 0;
}
