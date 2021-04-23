//https://codeforces.com/contest/1512/problem/C
//C. A-B Palindrome
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
        int a, b;
        cin >> a >> b;
        string s;
        cin >> s;
        const int n = (int)s.size();
        for(char c : s){
          if(c == '0') a--;
          if(c == '1') b--;
        }
        for(int i = 0; i <= n-i-1 ; ++i){ //a = '0'
          if(s[i] != '?' && s[n-i-1] != '?'){
              if(s[i] != s[n-i-1]){
                a = -1;
                break;
              }
              continue;
          }
          if(s[i] == s[n-i-1]) continue;
          if(s[i] == '?'){
            if(s[n-i-1] == '0'){
              s[i] = '0';
              a--;
              if(a < 0){
                a = -1;
                break;
              }
            }else{
              s[i] = '1';
              b--;
              if(b < 0){
                a = -1;
                break;
              }
            }
          }

          if(s[n-i-1] == '?'){
            if(s[i] == '0'){
              s[n-i-1] = '0';
              a--;
              if(a < 0){
                a = -1;
                break;
              }
            }else{
              s[n-i-1] = '1';
              b--;
              if(b < 0){
                a = -1;
                break;
              }
            }
          }
        }

        

        if(a < 0 || b < 0 || (a%2 && b%2)){
          cout << -1 << '\n';
          continue;
        }

        for(int i = 0; i <= n-i-1 ; ++i){
          if(s[i] != '?') continue;
          if(a > 1) {
              s[i] = s[n-i-1] = '0';
              a-=2;
          }else if(b > 1){
              s[i] = s[n-i-1] = '1';
              b-=2;
          }else if(i == n-i-1){
            if(a > 0) {
              s[i] = '0';
              a--;
            }else{
              s[i] = '1';
              b--;
            }
          }
        }
        if(a != 0 || b != 0){
          cout << -1 << '\n';
          continue;
        }
        cout << s << '\n';
    }
    return 0;
}
