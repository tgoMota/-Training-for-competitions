//https://www.urionlinejudge.com.br/judge/pt/problems/view/1629
//URI 1629 - DescompactaFACE
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
    while(cin >> t && t){
      for(int ti = 1; ti <= t ; ++ti){
          string num;
          cin >> num;
          int zeros = 0, ones = 0;
          for(int i = 0; i < (int)num.size() ; ++i){
            if(i%2 == 0) zeros += num[i]-'0';
            else ones+=num[i]-'0';
          }

          string a = to_string(zeros), b = to_string(ones);
          int sum = 0;
          for(char c : a){
            sum += c-'0';
          }

          for(char c : b){
            sum += c-'0';
          }

          cout << sum << '\n';
      }
    }
    return 0;
}

