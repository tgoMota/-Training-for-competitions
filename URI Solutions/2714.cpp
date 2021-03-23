//https://www.urionlinejudge.com.br/judge/pt/problems/view/2714
//URI 2714 - Minha Senha Provisória
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
    int t;
    cin >> t;
    for(int ti = 1; ti <= t ; ++ti){
        string line;
        cin >> line;
        const int N = (int)line.size();
        if(N < 20 || line.substr(0,2) != "RA") cout << "INVALID DATA\n";
        else{
          bool ok = true;
          int firstd = oo;
          for(int i = 2; i < N ; ++i){
            if(!isdigit(line[i])){
              ok = false;
              break;
            }
            if(line[i] != '0') firstd = min(firstd, i);
          }
          
          if(!ok) cout << "INVALID DATA\n";
          else cout << line.substr(firstd, N-firstd) << '\n';
        }
    }
    return 0;
}

