//https://www.urionlinejudge.com.br/judge/pt/problems/view/1231
//URI 1231 - Palavras
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

vector<vector<string>> v;
map<string, bool> mp1, mp2;
int n1, n2;

bool dfs(string a, string b){
  const int sa = (int)a.size();
  const int sb = (int)b.size();
  int i;
  for(i = 0; i < sa && i < sb ; ++i){
    if(a[i] != b[i]) return false;
  }
  if(i == sa && i == sb) return true;
  else if(i == sb){
    string c = a.substr(i,sa-i+1);
   // trace(a, c, i);
    if(mp1.find(c) != mp1.end()) return false;
    mp1[c] = true;
    for(int j = 0; j < n2 ; ++j){
      if(dfs(c, v[1][j])) return true;
    }
  }else{
    string c = b.substr(i,sb-i+1);
   // trace(b, c, i);
    if(mp2.find(c) != mp2.end()) return false;
    mp2[c] = true;
    for(int j = 0; j < n1 ; ++j){
      if(dfs(v[0][j], c)) return true;
    }
  }
  return false;
}
int main(){
    while(scanf("%d%d", &n1, &n2) != EOF){
      v.assign(2, vector<string>());
      mp1.clear();
      mp2.clear();
      for(int i = 0; i < n1 ; ++i){
        string a;
        cin >> a;
        v[0].push_back(a);
      }
      for(int i = 0; i < n2 ; ++i){
        string a;
        cin >> a;
        v[1].push_back(a);
      }
      bool ok = false;
      for(int i = 0; i < n1 && !ok ; i++){
        for(int j = 0; j < n2; j++){
          if(dfs(v[0][i],v[1][j])){
            ok = true;
            break;
          }
        }
      }
      printf("%s\n", ok ? "S" : "N");
    }
    return 0;
}