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
vector<int> pref;
struct suffixArray{
    vector<int> SA, tempSA, RA, tempRA, c;
    vector<int> LCP, Phi, PLCP;
    string s;
    int N;
    suffixArray(){}
    suffixArray(string _s, int ndelete){
        s = _s;
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
        for(int i = 0; i < ndelete ; ++i){
          SA.pop_back();
          LCP.pop_back();
        }
    }

    void countingSort(int k){
        int sum = 0, maxi =  max(300,N);
        c.assign(maxi, 0);
        for(int i = 0; i < N ; ++i) c[RA[(i+k)%N]]++;
        for(int i = 1; i < maxi ; ++i) c[i]+=c[i-1];
        for(int i = N-1 ; i >= 0 ; --i) tempSA[--c[RA[(SA[i]+k)%N]]] = SA[i];
        SA.swap(tempSA);
    }

    void buildSA(){ //SA construction in O(NlogN) using radix sort
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
            RA.swap(tempRA);
            if(RA[SA[N-1]] == N-1) break;
        }
    }

    void buildLCP(){ //Longest Common Prefix in O(N)
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

    void printSA(){
        cout << "SA: ";
        for(int i = 0; i < (int)SA.size() ; ++i) cout << SA[i] << ' ';
        cout << '\n';
    }

    void printLCP(){
      cout << "LCP: ";
      for(int i = 0; i < (int)LCP.size() ; ++i) cout << LCP[i] << ' ';
      cout << '\n';
    }

    void printAll(string str){
      for(int i = 0; i < (int)LCP.size() ; ++i){
        cout << SA[i] << ": " << str.substr(SA[i], LCP[i]) << '\n';
      }
    }
};

int main(){
    fastio();
    int n, t = 0;
    while(cin >> n && n){
      if(t++) cout << '\n';
      int sum = 0;
      vector<string> v(n);
      string tot = "";
      char conc = 120;
      for(int i = 0; i < n ; ++i){
        cin >> v[i];
        for(char& c : v[i]) c-='a';
        tot+=v[i];
        tot.push_back(conc);
        conc--;
        sum += (int)v[i].size();
      }
      suffixArray SA(tot,n);
      for(char& c : tot) {
        if(c > 'z'-'a') c = '$';
        else c += 'a';
      }
      trace(tot);
       SA.printLCP();
       
      // SA.printSA();
      //SA.printAll(tot);
      pref.assign(sum+n, 0);
      sum = 0;
      pref[0] = 1;
      for(int i = 1; i < n ; ++i){
        sum += (int)v[i-1].size()+1;
        pref[sum] = 1;
      }
      
      // auto sameOwner = [&](int i, int L){
      //   return pref[i] == pref[i+L];
      // };
      for(int i = 1; i < (int)pref.size() ; ++i) pref[i]+=pref[i-1];
      cout << "pre: ";
       for(int i = 0; i < SA.SA.size() ; ++i) cout << pref[SA.SA[i]] << " ";
       cout << '\n';
      int half = n/2, ans = 0;
      set<ii> s1;
      set<int> s2;
      set<string> finalAns;
      queue<int> q;
      vector<int> inq(pref.back()+1, 0);
      for(int i = 0; i < (int)SA.LCP.size() ; ++i){
        q.push(i);
        s1.insert({SA.LCP[i], i});
        s2.insert(pref[SA.SA[i]]);
        inq[pref[SA.SA[i]]]++;
        if((int)s2.size() <= half){
          continue;
        }
        while((int)s2.size() > half){
          auto val = (*s1.begin());
          if(val.first > ans){
            finalAns.clear();
            ans = val.first;
          }
          if(val.first == ans){
            finalAns.insert(tot.substr(SA.SA[i], ans));
          }
          int tx = q.front();
          trace(ans, tx, i, SA.SA[tx], SA.LCP[tx], q.size());
          if(inq[pref[SA.SA[tx]]] == 1 && (int)s2.size() == half+1) break;
          inq[pref[SA.SA[tx]]]--;
          if(inq[pref[SA.SA[tx]]] == 0) s2.erase(pref[SA.SA[tx]]);
          s1.erase({SA.LCP[tx],tx});
          q.pop();
          // if(q.empty()){
          //   trace((int)s1.size(), (int)s2.size());
          //   break;
          // }
        } 
      }
      for(string x : finalAns) cout << x << '\n';
      if(ans == 0) cout << "?\n";
      trace(ans, half);
    }
    return 0;
}

