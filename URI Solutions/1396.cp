//https://www.urionlinejudge.com.br/judge/pt/problems/view/1396s
//URI 1396 - Hoje tem Prova da Cris!
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
//CHECK THE LIMITS, PLEASE
int n, k;
vector<string> v;
int main(){
    fastio();
    int t = 1;
    
    while(cin >> n >> k && n+k){
      v.resize(n);
      for(string& s : v) cin >> s;

      for(int i = 0; i < n ; ++i){
        string mx = v[i];
        int posmx = i;
        for(int j = i+1; j < n && k >= j-i ; ++j){
          if(v[j] < mx){
            mx = v[j];
            posmx = j;
          }
        }

        k-= (posmx-i);
        for(int j = posmx; j > i ; --j){
          swap(v[j], v[j-1]);
        }
      }
      cout << "Instancia " << t++ << '\n';
      for(string s : v) cout << s << " ";
      cout << "\n\n";
    }
    return 0;
}
