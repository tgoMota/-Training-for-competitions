//https://www.urionlinejudge.com.br/judge/pt/problems/view/1276
//URI 1276 - Faixa de Letras
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
    string line;
    while(getline(cin, line)){
      unordered_map<char, bool> mp;
      for(char c : line){
        mp[c] = true;
      }
      vector<string> ans;
      for(char c  = 'a'; c <= 'z' ; ){
        if(!mp.count(c)){
          c++;
          continue;
        }
        string tmp = "";
        tmp+=c;
        tmp += ":";
        while(mp.count(++c)){}
        tmp+= (c-1);
        ans.push_back(tmp);
      }
      for(int i = 0; i < (int)ans.size(); ++i){
        if(i) cout << ", ";
        cout << ans[i];
      }
      cout << '\n';
    }
    return 0;
}

