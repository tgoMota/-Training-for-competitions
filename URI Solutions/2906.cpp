//https://www.urionlinejudge.com.br/judge/pt/problems/view/2906
//URI2906 - Database of Clients
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
    map<string, int> mp;
    int ans = 0;
    for(int ti = 1; ti <= t ; ++ti){
        string line;
        getline(cin, line);
        string username = "", last = "";
        int i;
        for(i = 0; i < (int)line.size() && line[i] != '@' ; ++i){
          username += line[i];
        }
        for(; i < (int)line.size() ; ++i){
          last += line[i];
        }
        istringstream ss(username);
        string token;
        vector<string> tokens;
        int id = -1;
        while(getline(ss, token, '+')){
          token.erase(remove(token.begin(), token.end(), '.'), token.end());
          tokens.push_back(token+last);
          if(id == -1 && mp.count(tokens.back())) {
            id = mp[tokens.back()];
          }
        }
        if(id == -1) {
          ans++;
          id = ti;
        }

        for(string& x : tokens) mp[x] = id;
        
    }

    cout << ans << '\n';
    return 0;
}

