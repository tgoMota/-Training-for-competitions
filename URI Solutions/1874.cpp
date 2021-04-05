//https://www.urionlinejudge.com.br/judge/pt/problems/view/1874
//URI 1874 - Empurrando Blocos
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
    int h, p, f;
    while(cin  >> h >> p >> f && (h+p+f)){
      vector<vector<int>> grid(h, vector<int>(p, 0));
      for(int i = 0; i < h ; ++i){
        for(int j = 0; j < p ; ++j){
          cin >> grid[i][j];
        }
      }
      int pos = p-1;
      for(int i = 0; i < f  ;  ++i){
        int a;
        cin >> a;
        while(pos > 0  &&  grid[0][pos] != 0) pos--;
        if(grid[0][pos] != 0) continue;
        for(int j = h-1; j >= 0 ; --j){
          if(grid[j][pos] == 0){
            grid[j][pos] = a;
            break;
          }
        }
      }

      for(int i  = 0; i  < h ; ++i){
        for(int j = 0; j  < p  ; ++j){
          if(j) cout << ' ';
          cout << grid[i][j];
        }
        cout << '\n';
      }
    }
    return 0;
}
