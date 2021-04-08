//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=660
//UVA 719 - Glass Beads
#include <bits/stdc++.h>
using namespace std;
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
typedef pair<int,int> ii;

struct suffixArray{
    vector<int> SA, tempSA, RA, tempRA, c;
    string s;
    int N;
    suffixArray(){}
    suffixArray(string _s){
        //s = _s + "$";
        s = _s;
        N = (int)s.size();
        SA.assign(N, 0);
        RA.assign(N, 0);
        tempSA.assign(N, 0);
        tempRA.assign(N, 0);
        buildSA();
        //SA.erase(SA.begin());
        //s.pop_back();
    }

    void countingSort(int k){
        int sum = 0, maxi =  max(256,N);
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
            int r = 0;
            tempRA[SA[0]] = 0;
            for(int i = 1; i < N ; ++i){
                tempRA[SA[i]] =  (ii(RA[SA[i]], RA[(SA[i]+k)%N]) == ii(RA[SA[i-1]], RA[(SA[i-1]+k)%N]) ? r : ++r);
            }
            RA = tempRA;
            if(RA[SA[N-1]] == N-1) break;
        }
    }

    void printSA(){
        cout << "SA: ";
        for(int i = 0; i < N ; ++i) cout << SA[i] << ' ';
        cout << '\n';
    }
};

int main(){
    int t;
    cin >> t;
    while(t--){
        string line;
        cin >> line;
        suffixArray t(line);
        //t.printSA();
        cout << t.SA[0]+1 << '\n';
    }
    
    return 0;
}