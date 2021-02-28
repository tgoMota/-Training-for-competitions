//https://www.urionlinejudge.com.br/judge/pt/problems/view/1707
//URI 1707 - Jogo com Números
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
ll memo[15][105][2][2][2][10];
ll solve(int idx, int sum, bool tightA, bool tightB, bool valid,int last, string& a, string& b){
  if(idx == (int)a.size()) return valid && (last % 2) ? sum : 0;
  ll& ans = memo[idx][sum][tightA][tightB][valid][last];
  if(ans != -1) return ans;
  int limitA = tightA ? a[idx]-'0' : 0;
  int limitB = tightB ? b[idx]-'0' : 9; //010 //100
  ans = 0LL;
  for(int i = limitA; i <= limitB ; ++i){
    int digitA = a[idx]-'0', digitB = b[idx]-'0';
    bool newTightA = tightA && (i==digitA);
    bool newTightB = tightB && (i==digitB);
    bool newValid = valid || (i > 0);
    ans += solve(idx+1, sum + i, newTightA, newTightB, newValid,i, a, b);
  }
  return ans;
}

int main(){
    fastio();
    int a, b;
    while(cin >> a >> b){
      if(a > b) swap(a,b);
      string num_a = to_string(a), num_b = to_string(b);
      const int N = (int)num_a.size(), M = (int)num_b.size();
      num_a.insert(num_a.begin(),M-N,'0');
      memset(memo, -1LL, sizeof(memo));
      cout << solve(0,0,true,true,false,0,num_a,num_b) << '\n';
    }
    return 0;
}

