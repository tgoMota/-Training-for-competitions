//https://codeforces.com/contest/1555/problem/D
//D. Say No to Palindromes
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

int id(char c){
  if(c == 'a') return 0;
  if(c == 'b') return 1;
  return 2;
}
int main(){
    fastio();
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector<vector<int>> prefs;
    string temp = "abc";
    do{
      vector<int> pref(n);
      for(int i = 0, j = 0; i < n ; ++i, j=(j+1)%3){
        pref[i] = (s[i] != temp[j]);
        if(i) pref[i]+=pref[i-1];
      }
      prefs.push_back(pref);
    }while(next_permutation(temp.begin(), temp.end()));


    while(m--){
      int a, b;
      cin >> a >> b;
      a--, b--;
      int ans = n;
      for(int i = 0; i < (int)prefs.size() ; ++i){
        if(a) ans = min(ans, prefs[i][b]-prefs[i][a-1]);
        else ans = min(ans, prefs[i][b]);
      }

      cout << ans << '\n';
    }

    return 0;
}
