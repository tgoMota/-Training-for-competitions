//https://codeforces.com/contest/628/problem/D
//D. Magic Numbers
#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
#define ooLL 0x3f3f3f3f3f3f3f3f
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
typedef long long ll;
typedef vector<pair<int,int>> vii;
typedef pair<int,int> pii;
const int mod = 1e9+7;

int memo[2005][2005][2][2];

int solve(int idx, int rem, bool tightA, bool tightB, string& A, string& B, const int N, const int D, const int M){
    if(idx == N) return rem == 0;
    int& ans = memo[idx][rem][tightA][tightB];
    if(ans != -1) return ans;
    int limitA = tightA? 0: A[idx]-'0';
    int limitB = tightB? 9: B[idx]-'0';
    ans = 0;
    for(int i = limitA ; i <= limitB ; ++i){
        if((idx&1)^(i==D)) continue;
        int newRem = (rem*10+i)%M;
        int newTightA = tightA || (i > (A[idx]-'0'));
        int newTightB = tightB || (i < (B[idx]-'0'));
        ans = (ans + solve(idx+1, newRem, newTightA, newTightB, A, B, N, D, M))%mod;
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int M, D;
    string A, B;
    cin >> M >> D >> A >> B;
    memset(memo, -1, sizeof(memo));
    cout << solve(0,0,0,0,A,B,(int)A.size(), D, M) << endl;
    return 0;
}