//https://codeforces.com/contest/1492/problem/C
//C. Maximum width
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
int N, M;
string a, b;
map<char,vector<int>> mp;
int main(){
    fastio();
    cin >> N >> M;
    cin >> a;
    cin >> b;
    vector<int> l(M), r(M);
    int i = 0, j = 0;
    while(j < M){
      while(a[i] != b[j]) i++;
      l[j] = i;
      j++, i++;
    }

    i = N-1, j = M-1;
    while(j >= 0){
      while(a[i] != b[j]) i--;
      r[j] = i;
      j--, i--;
    }
    int ans = 0;
    for(int i = 1; i < M ; ++i){
      ans = max(ans, r[i]-l[i-1]);
    }
    cout << ans << '\n';
    return 0;
}
