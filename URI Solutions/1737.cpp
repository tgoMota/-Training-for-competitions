//https://www.urionlinejudge.com.br/judge/pt/problems/view/1737
//URI 1737 - Etaoin Shrdlu
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
    int n;
    while(cin >> n && n){
      cin.ignore();
      map<string, int> cnt;
      string frase = "", line;
      for(int i = 0; i < n ; ++i){
        getline(cin, line);
        frase+=line;
      }
      const int N = (int)frase.size();
      int tot = N-1;
      for(int i = 0; i < N-1 ; ++i){
        cnt[frase.substr(i,2)]++;
      }
      vector<pair<int, string>> v;
      for(auto x : cnt){
        v.push_back({x.second, x.first});
      }

      sort(v.begin(), v.end(), [&](pair<int, string> &a, pair<int, string> &b){
        if(a.first == b.first) return a.second < b.second;
        return a.first > b.first;
      });
      for(int i = 0; i < (int)v.size() && i < 5 ; ++i){
        cout << fixed << setprecision(6) << v[i].second << " " << v[i].first << " " << v[i].first/(double)tot << '\n';
      }
      cout << '\n';
    }
    return 0;
}

