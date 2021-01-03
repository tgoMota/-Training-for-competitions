#include <bits/stdc++.h>
using namespace std;
string seq = "AGCT";
set<string> st;
void back(int idx, int rest, string currentSeq ,const int N, const int K){
    if(rest == 0){
        st.insert(currentSeq);
        return;
    }
    if(idx >= N) return;
    back(idx+1, rest, currentSeq, N, K);
    for(int i = 0; i < 4 ; ++i){
        currentSeq[idx] = seq[i];
        back(idx+1, rest-1, currentSeq,N, K);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        string iniSeq;
        cin >> iniSeq;
        st.clear();
        back(0,k,iniSeq,n,k);

        cout << (int)st.size() << '\n';
        for(string x : st)
            cout << x << '\n';
    }
    return 0;
}