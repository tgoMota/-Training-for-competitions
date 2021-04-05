//https://www.urionlinejudge.com.br/judge/pt/problems/view/1077
//URI 1077 - Infixa para Posfixa
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

map<char,int> mp;

int main(){
    fastio();
    int t;
    cin >> t;
    set<char> op = {'+', '-', '*', '/', '^'};
    mp['('] = mp[')'] = 0;
    mp['+'] = mp['-'] = 1;
    mp['*'] = mp['/'] = 2;
    mp['^'] = 3;
    for(int ti = 1; ti <= t ; ++ti){
        string line;
        cin >> line;
        string st = "", ans = "";
        const int N = (int)line.size();
        for(int i = 0; i < N ; ++i){
         if(op.count(line[i])){
           while(!st.empty() && mp[st.back()] >= mp[line[i]]){
             ans+=st.back();
             st.pop_back();
           }
           st.push_back(line[i]);
         }else if(line[i] == '('){
           st.push_back(line[i]);
         }else if(line[i] == ')'){
           while(!st.empty() && st.back() != '('){
             ans+=st.back();
             st.pop_back();
           }
           st.pop_back();
         }else ans+=line[i];
      }

      reverse(st.begin(), st.end());
      cout << (ans+st) << '\n';
    }
    return 0;
}