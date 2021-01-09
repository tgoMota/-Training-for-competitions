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
int n;
bool isHill(int idx){
  if(idx == 0 || idx == n-1) return false;
  if(v[idx] > v[idx-1] && v[idx] > v[idx+1]) return true;
  return false;
}

bool isValley(int idx){
  if(idx == 0 || idx == n-1) return false;
  if(v[idx] < v[idx-1] && v[idx] < v[idx+1]) return true;
  return false;
}

bool isSomething(int idx){
  return isHill(idx) || isValley(idx);
}

int tryBoth(int idxChange){
  int original = 0, idxBegin = idxChange-1;
  for(int i = idxBegin; i <= idxBegin+2; i++){
    if(isSomething(i)) original++;
  }
  if(original == 0) return 0;
  int cp = v[idxChange];
  v[idxChange] = v[idxChange-1];
  int cnt1 = 0;
  for(int i = idxBegin; i <= idxBegin+2; i++){
    if(isSomething(i)) cnt1++;
  }

  v[idxChange] = v[idxChange+1];
  int cnt2 = 0;
  for(int i = idxBegin; i <= idxBegin+2; i++){
    if(isSomething(i)) cnt2++;
  }
  
  v[idxChange] = cp;
  int minVal = min(cnt1, cnt2);
  if(minVal > original) return 0;
  return original-minVal;
}
int main(){
    int t;
    scanf("%d", &t);
    for(int ti = 1; ti <= t ; ++ti){
        scanf("%d", &n);
        v.resize(n);
        for(int& x : v) scanf("%d", &x);
        int cnt = 0, ans = 0;
        for(int i = 1; i < n-1 ; ++i){
          if(isSomething(i)) cnt++;
          ans = max(ans, tryBoth(i));
        }
        printf("%d\n", cnt-ans);

    }
    return 0;
}