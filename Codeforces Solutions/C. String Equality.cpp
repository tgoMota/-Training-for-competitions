//C. String Equality
//https://codeforces.com/problemset/problem/1451/C
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

int main(){
    int t;
    cin >> t;
    while(t--){
      int n, k;
      cin >> n >> k;
      string strA, strB;
      cin >> strA >> strB;
      map<char,int> freqA, freqB;
      for(char c : strA) freqA[c]++;
      for(char c : strB) freqB[c]++;

      bool ok = true;
      for(int i = 'a'; i <= 'z' ;  ++i){
        freqA[i]+=freqA[i-1];
        if(freqA[i] < freqB[i] || (freqA[i]-freqB[i])%k){
          ok = false;
          break;
        }
        freqA[i]-=freqB[i];
      }

      cout << (ok ? "YES" : "NO") << '\n';
    }
    
    
    return 0;
}