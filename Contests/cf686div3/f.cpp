//https://codeforces.com/contest/1454/problem/F
//F. Array Partition
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

vector<int> v, pref, suf;

struct SegMin{
   vector<int> t;
   void build(int i, int l, int r){
     if(l == r) t[i] = v[l];
     else{
        int m = l + (r-l)/2;
        build(2*i, l, m);
        build(2*i+1, m+1, r);
        t[i] = min(t[2*i], t[2*i+1]);
     }
   }

   int query(int i, int l, int r, int ql, int qr){
     if(ql <= l && qr >= r) return t[i];
     if(qr < l || ql > r) return oo;
     int m = l + (r-l)/2;
     return min(query(2*i, l, m, ql, qr), query(2*i+1, m+1, r, ql, qr));
   }
    
   void init(const int n){
     t.assign(4*n+20, oo);
     build(1, 0, (int)v.size()-1);
   }
};

int main(){
    int t;
    scanf("%d", &t);
    SegMin sgb;
    for(int ti = 1; ti <= t ; ++ti){
        int n;
        scanf("%d", &n);
        v.clear();
        pref.clear();
        v.resize(n);
        for(int i = 0; i < n ; ++i) {
          scanf("%d", &v[i]);
          if(!i) pref.push_back(v[i]);
          else pref.push_back(max(pref.back(), v[i]));
        }
        suf.assign(n, 0);
        for(int i = n-1; i >= 0 ; i--){
          if(i == n-1) suf[i] = v[i];
          else suf[i] = max(v[i], suf[i+1]);
        }

        SegMin sg;
        sg.init(n);
        bool ok = false;
        for(int i = n-1; i >= 2 && !ok ; i--){
          int val = suf[i];
          int begin = (int)(lower_bound(pref.begin(), pref.end(), val) - pref.begin());
          int end = (int)(upper_bound(pref.begin(), pref.end(), val) - pref.begin());
          int lo = begin+1, hi = end, mid;
          while(lo <= hi){
            mid = lo + (hi-lo)/2;
            int q = sg.query(1,0,n-1,mid,i-1);
            if(q == val){
                if(i > mid && sg.query(1, 0, n-1, mid, i-1) == val){
                  printf("YES\n");
                  printf("%d %d %d\n", mid, i-mid, n-i);
                  ok = true;
                  break;
              }
            }
            if(q < val) lo = mid+1;
            else hi = mid-1;
          }
        }
        if(!ok) printf("NO\n");
    }
    return 0;
}