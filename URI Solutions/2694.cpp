//https://www.urionlinejudge.com.br/judge/pt/problems/view/2694
//URI 2694 - Problema com a Calculadora
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
        string s;
        cin >> s;
        vector<string> nums;
        const int N = (int)s.size();
        for(int i = 0; i < N ; ++i){
          while(i < N && isalpha(s[i])) i++;
          string nu = "";
          while(i < N && isdigit(s[i])){
            nu += s[i];
            i++;
          }
          nums.push_back(nu);
        }

        int sum = 0;
        for(string s : nums){
          sum += atoi(s.c_str());
        }
        cout << sum << '\n';
    }
    return 0;
}

