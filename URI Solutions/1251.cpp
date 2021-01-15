//https://www.urionlinejudge.com.br/judge/pt/problems/view/1251
//URI 1251 - Diga-me a Frequência
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
//CHECK THE LIMITS, PLEASE
int main(){
    string s;
    int t = 0;
    while(cin >> s){
      if(t++ != 0) printf("\n");
      map<char,int> freq;
      for(int i = 0; i < (int)s.size() ; ++i){
        freq[s[i]]++;
      }

      vector<ii> v;
      for(auto x : freq){
        v.push_back({x.second,x.first});
      }

      sort(v.begin(), v.end(), [&](ii& a, ii& b){
        if(a.first < b.first) return true;
        else if(a.first > b.first) return false;
        return a.second > b.second;
      });

      for(auto x : v) printf("%d %d\n", x.second, x.first);
    }
    return 0;
}
