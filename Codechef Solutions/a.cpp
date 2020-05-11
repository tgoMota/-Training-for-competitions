#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
#define ooLL 0x3f3f3f3f3f3f3f3f
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
const int mod = 1e9+7;
typedef long long ll;
typedef vector<pair<int,int>> vii;
typedef pair<int,int> pii;
ll memo[20][2][2][2][20];


ll solve(int idx, bool tightA, bool tightB, bool validA, int d, string& A, string& B, const int N, const int D){
    if(idx == N) return validA && d == 0;
    ll& ans = memo[idx][tightA][tightB][validA][d];
    if(ans != -1) return ans;
    int limitA = tightA? 0 : A[idx]-'0';
    int limitB = tightB? 9 : B[idx]-'0';
    ans = 0LL;
    for(int i = limitA ; i <= limitB ; ++i){
        bool newTightA = tightA || (i > A[idx]-'0');
        bool newTightB = tightB || (i < B[idx]-'0');
        bool newValidA = validA || (i > 0);
        int add = newValidA && d == i;
        ans += solve(idx+1, newTightA, newTightB, newValidA, d-add, A, B, N, D);
    }
    return ans;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    for(int ti = 1; ti <= t ; ++ti){
        string l, r;
        cin >> l >> r;
        vector<int> freq(10,0);
        for(int i = 0; i < 10 ; ++i) cin >> freq[i];

        const int N = l.size();
        const int M = r.size();

        if(M > N) l.insert(0, M-N, '0');
        ll ans = 0LL;
        for(int i = 0; i < 10 ; ++i){
            memset(memo, -1, sizeof(memo));
            ans += solve(0,0,0,0,freq[i],l,r, M, i);
        }
        cout << ans << endl;
    }

    return 0;
}