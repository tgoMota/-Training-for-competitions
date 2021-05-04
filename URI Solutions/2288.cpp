//https://www.urionlinejudge.com.br/judge/pt/problems/view/2288
//URI 2288 - TV da Vovó
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
    int t = 0, m, n;
    while (cin >> m >> n && m) {
      vector<vector<int>> grid(m+1, vector<int>(n+1));
      for (int i=0; i<m; i++) for (int j=0; j<n; j++) cin >> grid[i][j];
          int dx = 0, dy = 0, a, b;
          while (cin >> a >> b && (a || b)) {
            dx += a;
            dy += b;
          }
          cout << "Teste " << ++t << '\n';
          for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
              if (j) cout << " ";
              int new_y = (m+(i+dy)%m)%m;
              int new_x = (n+(j-dx)%n)%n;
              cout << grid[new_y][new_x];
            }
            cout << '\n';
          }
          cout << '\n';
        }
      return 0;
}
