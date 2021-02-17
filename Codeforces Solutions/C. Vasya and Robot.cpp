//C. Vasya and Robot
//https://codeforces.com/problemset/problem/1073/C
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
int n;
ii to;
string line;
vector<int> prefX, prefY;

int main(){
    cin >> n;
    cin >> line;
    cin >> to.first >> to.second;
    if(n < abs(to.first) + abs(to.second) || n%2 != (abs(to.first) + abs(to.second))%2){
      cout << -1 << '\n';
      exit(0);
    }
    ii tmp = {0,0};
    prefX.push_back(0);
    prefY.push_back(0);
    for(int i = 0; i < n ; ++i){
      if(line[i] == 'U') tmp.second++;
      if(line[i] == 'D') tmp.second--;
      if(line[i] == 'L') tmp.first--;
      if(line[i] == 'R') tmp.first++;
      prefX.push_back(tmp.first);
      prefY.push_back(tmp.second);
    }
    int ans = oo;
    for(int i = 0; i <= n ; ++i){
      int lo = i, hi = n+2; // (mid-1) would be equal to n
      while(lo < hi){
        int mid = (lo + hi) >> 1;
        int posx = prefX[i] + prefX[n] - prefX[mid-1]; //the interval that we want is [i+1, mid-1]
        int posy = prefY[i] + prefY[n] - prefY[mid-1];
        int needChange = abs(to.first - posx) + abs(to.second - posy);
        int willChange = mid-i;
        if(needChange < willChange) hi = mid;
        else lo = mid+1;
      }
      if(lo == n+2) continue;
      ans = min(ans, lo-i-1);
    }

    cout << ans << '\n';

    return 0;
}
