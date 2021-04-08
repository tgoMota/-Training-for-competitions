//https://onlinejudge.org/external/7/760.pdf
//UVA 760 DNA Sequencing
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

struct suffixArray{
    vector<int> SA, tempSA, RA, tempRA, c;
    vector<int> LCP, Phi, PLCP;
    string s;
    int N;
    suffixArray(){}
    suffixArray(string _s){
        s = _s + "$";
        N = (int)s.size();
        SA.assign(N, 0);
        RA.assign(N, 0);
        tempSA.assign(N, 0);
        tempRA.assign(N, 0);
        LCP.assign(N, 0);
        Phi.assign(N, 0);
        PLCP.assign(N, 0);
        buildSA();
        buildLCP();
        SA.erase(SA.begin(), SA.begin()+2);
        LCP.erase(LCP.begin(), LCP.begin()+2);
    }

    void countingSort(int k){
        int sum = 0, maxi =  max(300,N);
        c.assign(maxi, 0);
        for(int i = 0; i < N ; ++i) c[RA[(i+k)%N]]++;
        for(int i = 1; i < maxi ; ++i) c[i]+=c[i-1];
        for(int i = N-1 ; i >= 0 ; --i) tempSA[--c[RA[(SA[i]+k)%N]]] = SA[i];
        SA = tempSA;
    }

    void buildSA(){
        for(int i = 0; i < N ; ++i) {
            SA[i] = i;
            RA[i] = s[i];
        }
        for(int k = 1; k < N ; k <<= 1){
            countingSort(k);
            countingSort(0);
            int r = tempRA[SA[0]] = 0;
            for(int i = 1; i < N ; ++i){
                tempRA[SA[i]] =  (ii(RA[SA[i]], RA[(SA[i]+k)%N]) == ii(RA[SA[i-1]], RA[(SA[i-1]+k)%N]) ? r : ++r);
            }
            RA = tempRA;
            if(RA[SA[N-1]] == N-1) break;
        }
    }

    int owner(int i, int N, int L){
      return i+M <= L;
    }

    void buildLCP(){
        Phi[SA[0]] = -1;
        for(int i = 1; i < N ; ++i) Phi[SA[i]] = SA[i-1];
        for(int i = 0, k = 0; i < N ; ++i){
            if(Phi[i] == -1){
                PLCP[i] = 0;
                continue;
            }
            while(s[i+k] == s[Phi[i]+k]) ++k;
            PLCP[i] = k;
            k = max(k-1,0);
        }
        for(int i = 0; i < N ; ++i) LCP[i] = PLCP[SA[i]];
    }
};



int main(){
    fastio();
    string a, b;
    int t = 0;
    while(cin >> a >> b){
      if(t++) cout << '\n';
      const int N = (int)a.size();
      string r = a + "!" + b;
      suffixArray SA(r);
      int best = 0;
      for(int i = 1; i < SA.N ; ++i){
        if(SA.owner(SA.SA[i-1], N, SA.LCP[i]) != SA.owner(SA.SA[i], N, SA.LCP[i])) best = max(best, SA.LCP[i]);
      }
      if(best == 0){
        cout << "No common sequence.\n";
        continue;
      }
      set<string> s;
      for(int i = 1; i < SA.N ; ++i){
        if(SA.LCP[i] == best && SA.owner(SA.SA[i-1], N, best) != SA.owner(SA.SA[i], N, best)){
          s.insert(r.substr(SA.SA[i], SA.LCP[i]));
        } 
      }
      for(auto x : s) cout << x << '\n';
    }
    return 0;
}

