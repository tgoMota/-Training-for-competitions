//https://www.urionlinejudge.com.br/judge/pt/problems/view/1509
//URI 1509 - Contando Ambiguidades
#include <bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
const int mod = 1e9+7;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
//CHECK THE LIMITS, PLEASE
set<string> words;
vector<ll> memo;
int n;

ll dfs(int idx, string& s){
  if(idx == (int)s.size()) return 1LL;
  ll& ans = memo[idx];
  if(ans != -1) return ans;
  const int N = s.size()-idx;
  ans = 0LL;
  for(int i = 0; i < N ; ++i){
    string sub = s.substr(idx, i+1);
    if(words.count(sub) == 0) continue;
    ans = (ans + dfs(idx+i+1, s))%mod;
  }
  return ans;
}

int main(){
    fastio();
    while(cin >> n){
      words.clear();
      for(int i = 0; i < n ; ++i){
        string s;
        cin >> s;
        words.insert(s);
      }
      int q;
      cin >> q;
      while(q--){
        string s;
        cin >> s;
        memo.assign((int)s.size()+1, -1LL);
        ll ans = dfs(0, s) % mod;
        cout << ans << '\n';
      }
    }
    return 0;
}
