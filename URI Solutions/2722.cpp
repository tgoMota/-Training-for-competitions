//https://www.urionlinejudge.com.br/judge/pt/problems/view/2722
//URI 2722 - Pegadinha de Evergreen
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
    cin.ignore();
    for(int ti = 1; ti <= t ; ++ti){
        string a, b;
        getline(cin, a);
        getline(cin, b);
        string ans = "";
        const int N = (int)a.size();
        const int M =(int)b.size();
        for(int i = 0, j = 0, turn = 0; i < N || j < M ; turn = (turn+1)%2){
          if(turn == 0 && i < N){
            ans += a[i++];
            ans += a[i++];
          }
          if(turn == 1){
            if(j < M) ans += b[j++];
            if(j < M) ans += b[j++];
          }
        }

        cout << ans << '\n';
    }
    return 0;
}

