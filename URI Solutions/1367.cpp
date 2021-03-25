//https://www.urionlinejudge.com.br/judge/pt/problems/view/1367
//URI 1367 - Ajude!
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
    int n;
    while(cin >> n && n){
      map<string,int> penalt;
      map<string, int> accept;
      string q;
      int t, sumt = 0;
      string veredict;
      for(int i = 0; i < n ; ++i){
         cin >> q >> t >> veredict;
         if(veredict == "incorrect") {
          penalt[q]+=20;
         }
         else {
           if(!accept.count(q)) accept[q] = t + penalt[q];
         }
      }

      for(auto x : accept) sumt+=x.second;

      cout << (int)accept.size() << " " << sumt << '\n';

    }
    return 0;
}

