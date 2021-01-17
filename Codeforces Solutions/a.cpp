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
//CHECK THE LIMITS, PLEASE
vector<int> v;
vector<vector<int>> pos, pref, suf;

struct Seg{
  vector<int> t;
  Seg(int n){
    t.assign(4*n, 0);
  }

  void build(int i, int l, int r){
    if(l == r) t[i] = v[l];
    else{
      int mid = (l+r)>>1;
      build(2*i, l, mid);
      build(2*i+1, mid+1, r);
      int left = t[2*i];
      int right = t[2*i+1];
      int szleft = (int)pos[left].size();
      int szright = (int)pos[right].size();
      if()
    }
  }

}

int main(){
    int t;
    scanf("%d", &t);
    for(int ti = 1; ti <= t ; ++ti){
        int n;
        scanf("%d", &n);
        v.resize(n);
        pos.assign(201,vector<int>());
        vector<int> cnt(201);
        for(int i = 0; i < n ; ++i){
          scanf("%d", &v[i]);
          cnt[v[i]]++;
          pos[v[i]].push_back(i);
        }

        pref.assign(n, vector<int>(201, 0));
        pref[0][v[0]]++;
        for(int i = 1; i < n ; ++i){
          pref[i] = pref[i-1];
          pref[i][v[i]]++;
        }

        suf.assign(n, vector<int>(201, 0));
        suf[n-1][v.back()]++;
        for(int i = n-2; i >= 0 ; --i){
          suf[i] = suf[i+1];
          suf[i][v[i]]++;
        }
    }
    return 0;
}
