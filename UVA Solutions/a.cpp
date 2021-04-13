//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2507
//UVA 11512 - GATTACA
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

struct suffixArray{
  string s;
  int N;
  vector<int> SA, tempSA, RA, tempRA, c;
  vector<int> LCP, PLCP, Phi;
  suffixArray(){}
  suffixArray(string _s){
    s = _s + "$";
    N = (int)s.size();
    SA.assign(N, 0);
    tempSA.assign(N, 0);
    RA.assign(N, 0);
    tempRA.assign(N, 0);
    LCP.assign(N, 0);
    PLCP.assign(N, 0);
    Phi.assign(N, 0);
    buildSA();
    buildLCP();
    SA.erase(SA.begin());
    LCP.erase(LCP.begin());
  }

  void countingSort(int k){
    int maxi = max(256, N);
    c.assign(maxi, 0);
    for(int i = 0; i < N; ++i) ++c[RA[(i+k)%N]];
    for(int i = 1; i < maxi ; ++i) c[i]+=c[i-1];
    for(int i = N-1; i >= 0 ; --i) tempSA[--c[RA[(SA[i]+k)%N]]] = SA[i];
    tempSA.swap(SA);
  }

  void buildSA(){
    for(int i = 0; i < N ; ++i){
      SA[i] = i;
      RA[i] = s[i];
    }

    for(int k = 1; k < N ; k<<=1){
      countingSort(k);
      countingSort(0);

      int r = tempRA[SA[0]] = 0;
      for(int i = 1; i < N ; ++i){
        tempRA[SA[i]] = (ii(RA[SA[i]], RA[(SA[i]+k)%N]) == ii(RA[SA[i-1]], RA[(SA[i-1]+k)%N]) ? r : ++r);
      }

      RA.swap(tempRA);
      if(RA[SA[N-1]] == N-1) break;
    }
  }

  void buildLCP(){
    Phi[SA[0]] = -1;
    for(int i = 1; i < N ; ++i) Phi[SA[i]] = SA[i-1];
    for(int i = 0, k = 0; i < N ; ++i){
      if(Phi[i] == -1){
        PLCP[i] = 0;
        continue;
      }

      while(s[i+k] == s[Phi[i]+k]) k++;
      PLCP[i] = k;
      k = max(k-1, 0);
    }
    for(int i = 0; i < N ; ++i) LCP[i] = PLCP[SA[i]];
  }
};

//CHECK THE CONSTRAINTS, PLEASE
int main(){
    fastio();
    int t;
    cin >> t;
    for(int ti = 1; ti <= t ; ++ti){
        string s;
        cin >> s;
        suffixArray SA(s);
        int ans = 0, cnt = 0;
        bool ok = false;
        for(int i = 0; i < (int)SA.LCP.size(); ++i){
          if(SA.LCP[i] > ans){
              ans = SA.LCP[i];
              cnt = 1;
              ok = true;
          }
          if(SA.LCP[i] == ans && ok) cnt++;
          else ok = false;
        }
        if(!ans){
          cout << "No repetitions found!\n";
          continue;
        }
        for(int i = 0; i < (int)SA.LCP.size() ; ++i){
          if(SA.LCP[i] == ans){
            cout << s.substr(SA.SA[i], SA.LCP[i]) << " " << cnt << '\n';
            break;
          }
        }
    }
    return 0;
}

