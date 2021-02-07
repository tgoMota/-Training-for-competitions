//https://codeforces.com/problemset/problem/489/B
//B. BerSU Ball
#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
#define ooLL 0x3f3f3f3f3f3f3f3f
#define fastio() ios_base::sync_with_stdio(false); cin.tie(0)
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
vector<int> a, b;
int n, m;
const int NAX = 105;
int main(){
    scanf("%d", &n);
    a.resize(n);
    for(int& x : a) scanf("%d", &x);
    scanf("%d", &m);
    b.resize(m);
    for(int& x : b) scanf("%d", &x);
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int i = 0, j = 0, ans = 0;
    while(i < n && j < m){
      int dist = abs(a[i]-b[j]);
      if(dist <= 1){
        ans++;
        i++, j++;
      }else if(a[i] < b[j]) i++;
      else if(b[j] < a[i]) j++;
    }
    printf("%d\n", ans);
    return 0;
}