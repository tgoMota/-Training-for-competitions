//https://codeforces.com/contest/476/problem/B
//B. Dreamoon and WiFi
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

int solve(int canUse, int curPos, const int destiny){
  if(!canUse) return curPos == destiny;
  return solve(canUse-1, curPos+1, destiny)+solve(canUse-1, curPos-1, destiny);
}

int main(){
    fastio();
    cout << fixed << setprecision(10);
    string sa, sb;
    cin >> sa >> sb;
    int pos = 0, cnt = 0;
    for(int i = 0; i < (int)sa.size() ; ++i){
      pos+= sa[i] == '+' ? 1 : -1;
      if(sb[i] != '?') pos+= sb[i] == '+' ? -1 : 1;
      else cnt++;
    }

    cout << solve(cnt, 0, pos)/pow(2,cnt) << '\n';

    return 0;
}
