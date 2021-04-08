#include <bits/stdc++.h>
using namespace std;
#define LOCAL
#ifdef LOCAL
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
#else
#define trace(...) 42
#endif
#define oo 0x3f3f3f3f
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
    vector<int> LCP, Phi, PLCP;
    string s;
    int N;
    suffixArray(){}
    suffixArray(string _s){
        s = _s + "!";
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
        SA.erase(SA.begin());
        LCP.erase(LCP.begin());
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

    void printSA(){
        cout << "SA: ";
        for(int i = 0; i < N ; ++i) cout << SA[i] << ' ';
        cout << '\n';
    }

    void printLCP(){
        trace(s);
        cout << "LCP: ";
        for(int i = 0; i < LCP.size() ; ++i) cout << LCP[i] << ' ';
        cout << '\n';
        cout << "IDX: ";
        for(int i = 0; i < LCP.size() ; ++i) cout << i << ' ';
        cout << '\n';
    }

    void printAllSu(){
        for(int i = 0; i < SA.size() ; ++i) cout << SA[i] << ": " <<s.substr(SA[i], LCP[i]) << '\n';
    }
};
unordered_map<char,int> firstOc;
string line;

struct minqueue{
    deque<pair<int,int>> q;
    int cnt_added, cnt_removed;
    minqueue(){
        clear();
    }
    void push(int new_element){
        while (!q.empty() && q.back().first > new_element) q.pop_back();
        q.push_back(make_pair(new_element, cnt_added));
        cnt_added++;
    }

    int getMin(){
        return q.front().first;
    }

    void pop(){
        if (!q.empty() && q.front().second == cnt_removed) q.pop_front();
        cnt_removed++;
    }
    void clear(){
        cnt_added = cnt_removed = 0;
        q.clear();
    }
};


int main(){
    int k;
    getline(cin, line);
    for(char& c : line) if(c == ' ') c = '$';

    cin >> k;
    if(k > (int)line.size()){
        cout << ":)\n";
        return 0;
    }
    if(k == 1){
        cout << line << '\n';
        return 0;
    }
    suffixArray SA(line);
    minqueue q;
    //SA.printSA();
    //SA.printLCP();
    //SA.printAllSu();
    int best = 0;
    for(int i = 0; i < (int)SA.SA.size() ; ++i){
        if(i < k-1){
            q.push(SA.LCP[i]);
            continue;
        }
        best = max(best, q.getMin());
        q.pop();
        q.push(SA.LCP[i]);
    }
    best = max(best, q.getMin());
    
    int posmin = oo;
    for(int i = 1; i < (int)SA.SA.size() ; ++i){
        if(SA.LCP[i] == best) posmin = min(posmin, min(SA.SA[i-1], SA.SA[i]));
    }
    for(char& c : line) if(c == '$') c = ' ';
    //trace(best, posmin, line, line.size(), SA.SA.size(), SA.LCP.size());
    if(best > 0) cout << line.substr(posmin, best) << '\n';
    else cout << ":)\n";
    return 0;
}
