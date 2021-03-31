//https://www.urionlinejudge.com.br/judge/pt/problems/view/2253
//URI 2253 - Validador de Senhas
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
    while(getline(cin, line) && line != "."){
      vector<pair<string,int>> v;
      vector<pair<int,string>> v2;
      map<string,string> mp;
      map<string,int> cnt;
      stringstream ss(line);
      string token;
      int idx = 0;
      while(getline(ss, token, ' ')){
        v.push_back({token, idx++});
        cnt[token] += (int)token.size();
      }
      sort(v.begin(), v.end(), [&](pair<string,int>& a, pair<string,int>& b){
        return cnt[a.first] > cnt[b.first];
      });

      for(pair<string,int>& x : v){
        string s = x.first.substr(0,1)+".";
        if((int)x.first.size() <= 2){
          v2.push_back({x.second, x.first});
          continue;
        }
        if(mp.count(s)) continue;
        mp[s] = x.first;
        v2.push_back({x.second,s});
      }
      sort(v2.begin(), v2.end());
      for(int i = 0; i < (int)v2.size() ; ++i){
        if(i) cout << " ";
        cout << v2[i].second;
      }
      cout << '\n';
      cout << (int)mp.size() << '\n';
      for(auto x : mp){
        cout << x.first << " = " << x.second << '\n';
      }
    }
}

