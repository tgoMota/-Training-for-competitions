//https://www.urionlinejudge.com.br/judge/pt/problems/view/3159
//URI 3159 - Tijolão
#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
#define ooLL 0x3f3f3f3f3f3f3f3f
#define fastio() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
const int mod = 1e9+7;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
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
//CHECK THE CONSTRAINTS, PLEASE
int main(){
    fastio();
    int t;
    cin >> t;
    map<char,string> mp;
    for(char ch = 'a', d = '2' ; ch <= 'z' && d <= '9' ; d++){
      int limit = (d == '7' || d == '9') ? 4 : 3;
      char cur = ch;
      for(int i = 1; i <= limit ; ++i){
        string sub = string(i, d);
        //trace(sub, d, cur);
        mp[cur] = sub;
        cur++;
      }
      ch+=limit;
    }
    mp[' '] = "0";
    cin.ignore();
    for(int ti = 1; ti <= t ; ++ti){
        string line;
        getline(cin, line);
        string ans = "";
        for(char& ch : line){
          if(ch >= 'A' && ch <= 'Z'){
            ans += '#';
            ch = tolower(ch);
          }
          string nxt = mp[ch];
          if(!ans.empty() && nxt[0] == ans.back()) ans+='*';
          ans+=nxt;
        }
        cout << ans << '\n';
    }
    return 0;
}

