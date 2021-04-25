//https://www.urionlinejudge.com.br/judge/pt/problems/view/2287
//URI 2287 - Proteja sua Senha
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
const int MAXM = 6;
int hashc(char c){
  return c-'A';
}
int main(){
    fastio();
    int n, t = 0;
    while(cin >> n && n){
      vector<vector<ii>> v(n, vector<ii>(5, ii()));
      vector<string> password(n, "");
      for(int i = 0; i < n ; ++i){

        for(int j = 0; j < 5 ; ++j) cin >> v[i][j].first >> v[i][j].second;
        for(int j = 0; j < MAXM ; ++j){
          char c;
          cin >> c;
          password[i]+=c;
        }
      }

      cout << "Teste " << ++t << '\n';
      vector<int> ans;
      for(int i = 0; i < MAXM ; ++i){
        ii op = v[0][hashc(password[0][i])];
        bool ok = true;
        for(int j = 1; j < n ; ++j){
          if (op.first != v[j][hashc(password[j][i])].first && op.first != v[j][hashc(password[j][i])].second) ok = false;
        }

        if(ok) ans.push_back(op.first);
        else ans.push_back(op.second);
      }

      for(int i = 0; i < MAXM ; ++i){
        cout << ans[i] << " ";
      }
      cout << "\n\n";
    }
    return 0;
}
