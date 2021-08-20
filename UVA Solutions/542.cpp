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
string v[16];
double m[16][16];

double solve(int idx, int mask, const int team){
  if(mask == (1<<team)) return 1;
  while(!(mask & (1<<idx))) idx = (idx+1)%16;
  int i = idx+1;
  while(!(mask & (1<<i))) i++;
  if(idx == team) return m[idx][i]*solve((i+1)%16, mask^(1<<i),team);
  else if(i == team) return m[i][idx]*solve((i+1)%16, mask^(1<<idx), team);
  return m[idx][i]*solve((i+1)%16, mask^(1<<i),team) + m[i][idx]*solve((i+1)%16, mask^(1<<idx), team);
}

int main(){
    for(int i = 0; i < 16 ; ++i) cin >> v[i];
    for(int i = 0; i < 16 ; ++i){
      for(int j = 0; j < 16 ; ++j){
        cin >> m[i][j];
        m[i][j]/=100.0;
      }
    }

    cout << setprecision(2) << fixed << left;
    for(int i = 0; i < 16 ; i++){
      double ans = solve(0, (1<<16)-1, i)*100.00;
      cout << setw(10) << v[i] << setfill(' ') << " p=" << ans << "%\n";
    }
    return 0;
}
