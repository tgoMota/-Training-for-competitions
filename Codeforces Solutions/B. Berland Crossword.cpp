//https://codeforces.com/contest/1494/problem/B
//B. Berland Crossword
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
int N, U, R, D, L;

bool solve(int mask, int u, int r, int d, int l){//1111
  if(mask & (1 << 0)){ //top left
    u--, l--;
  }
  if(mask & (1 << 1)){ //top right
    u--, r--;
  }
  if(mask & (1 << 2)){//bottom right
    d--, r--;
  }
  if(mask & (1 << 3)){ //bottom left
    d--, l--;
  }
  if(u < 0 || r < 0 || d < 0 || l < 0) return false;
  if(u > N-2 || r > N-2 || d > N-2 || l > N-2) return false;
  return true;
}
int main(){
    fastio();
    int t;
    cin >> t;
    for(int ti = 1; ti <= t ; ++ti){
        cin >> N >> U >> R >> D >> L;
        bool ok = false;
        for(int mask = 0; (mask < 1 << 4) ; ++mask){
          ok |= solve(mask, U, R, D, L);
        }
        cout << (ok ? "YES" : "NO") << '\n';
    }
    return 0;
}
