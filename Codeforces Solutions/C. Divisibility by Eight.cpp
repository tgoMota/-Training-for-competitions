//https://codeforces.com/problemset/problem/550/C
//C. Divisibility by Eight
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
    string num;
    cin >> num;
    const int N = (int)num.size();
    for(char c : num){
      if(c == '0' || c == '8'){
        cout << "YES\n";
        cout << c << '\n';
        return 0;
      }
    }

    for(int i = 0; i < N; ++i){
      for(int j = i+1; j < N ; ++j){
        for(int k = j+1; k < N ; ++k){
          int d1 = num[i]-'0';
          int d2 = num[j]-'0';
          int d3 = num[k]-'0';
          int num_tmp = d1*100 + d2*10 + d3;
          if(num_tmp%8 == 0){
            cout << "YES\n" << num_tmp << '\n';
            return 0;
          }
        }
      }
    }

    for(int i = 0; i < N; ++i){
      for(int j = i+1; j < N ; ++j){
        int d1 = num[i]-'0';
        int d2 = num[j]-'0';
        int num_tmp = d1*10+d2;
          if(num_tmp%8 == 0){
            cout << "YES\n" << num_tmp << '\n';
            return 0;
          }
      }
    }

    cout << "NO\n";

    return 0;
}
