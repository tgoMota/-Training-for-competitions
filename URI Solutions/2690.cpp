//https://www.urionlinejudge.com.br/judge/pt/problems/view/2690
//URI 2690 - Nova Senha RA
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
map<char, char> mp;
void pushAll(string keys, int value){
  for(char c : keys){
    mp[c] = value;
  }
}
int main(){
    fastio();
    int t;
    cin >> t;
    pushAll("GQaku", '0');
    pushAll("ISblv", '1');
    pushAll("EOYcmw", '2');
    pushAll("FPZdnx", '3');
    pushAll("JTeoy", '4');
    pushAll("DNXfpz", '5');
    pushAll("AKUgq", '6');
    pushAll("CMWhr", '7');
    pushAll("BLVis", '8');
    pushAll("HRjt", '9');
    string line;
    getline(cin, line);
    for(int ti = 1; ti <= t ; ++ti){
        getline(cin, line);
        string ans = "";
        for(int i = 0, cnt = 0; i < (int)line.size() && cnt < 12 ; ++i){
          if(!isalpha(line[i])) continue;
          ans += mp[line[i]];
          cnt++;
        }
        cout << ans << "\n";
    }
    return 0;
}

