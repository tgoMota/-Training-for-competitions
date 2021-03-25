//https://www.urionlinejudge.com.br/judge/pt/problems/view/2023
//URI 2023 - A Última Criança Boa
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
    string line;
    vector<string> v;
    while(getline(cin, line)){
      v.push_back(line);
    }
    auto tolow = [](char c){
      return tolower(c);
    };
    sort(v.begin(), v.end(), [&](string a, string b){
      string _a = a, _b = b;
      transform(_a.begin(), _a.end(), _a.begin(),tolow);
      transform(_b.begin(), _b.end(), _b.begin(),tolow);

      return lexicographical_compare(_a.begin(), _a.end(), _b.begin(), _b.end());
    });

    cout << v.back() << '\n';
    return 0;
}

