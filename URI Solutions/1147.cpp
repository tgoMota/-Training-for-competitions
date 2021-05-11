//https://www.urionlinejudge.com.br/judge/pt/problems/view/1147
//URI 1147 - Fuga do Cavalo
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
int horsex, horsey;
vector<vector<bool>> marked;
int dx[8] = {1,1,-1,-1,2,2,-2,-2}, dy[8] = {2, -2, 2, -2, 1, -1, 1, -1};
int main(){
    fastio();
    char a;
    int ca;
    int t = 1;
    while(cin >> ca && ca){
      cin >> a;
      marked.assign(9, vector<bool>(9, false));
      horsex = ca-1;
      horsey = a - 'a';
      for(int i = 0; i < 8 ; ++i){
        cin >> ca >> a;
        int x = ca-1, y = a-'a';
        if(x > 0 && y > 0) marked[x-1][y-1] = true;
        if(x > 0 && y < 7) marked[x-1][y+1] = true;
      }
      int ans = 0;
      for(int i = 0; i < 8 ; ++i){
        int new_x = horsex  + dx[i];
        int new_y = horsey + dy[i];
        if(new_x < 0 || new_x > 7 || new_y < 0 || new_y > 7) continue;
        if(!marked[new_x][new_y]) {
          ans++;
        }
      }
      cout << "Caso de Teste #" << t++ << ": " << ans << " movimento(s).\n";
    }
    return 0;
}
