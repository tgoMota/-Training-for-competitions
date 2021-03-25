//https://www.urionlinejudge.com.br/judge/pt/problems/view/1516
//URI 1516 - Imagem
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
    while(cin >> n >> m && n+m){
      vector<string> grid(n);
      for(int i = 0; i < n ; ++i){
        cin >> grid[i];
      }
      int A, B;
      cin >> A >> B;
      int multN = A/n, multM = B/m;
      for(int i = 0; i < n ; ++i){
        string new_line = "";
        for(int j = 0; j < grid[i].size() ; ++j){
          new_line+= string(multM, grid[i][j]);
        }
        for(int j = 0; j < multN ; ++j) {
          cout << new_line << '\n';
        }
      }
      cout << '\n';
    }
    return 0;
}

