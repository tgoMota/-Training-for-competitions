//https://codeforces.com/gym/100886/problem/G
//G. Maximum Product
#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
#define ooLL 0x3f3f3f3f3f3f3f3f
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
const int mod = 1e9+7;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<pair<int,int>> vii;
typedef pair<int,int> pii;

ll memo[20][2][2][2];

ll solve(int idx, bool tightA, bool tightB, bool validA, string& a, string& b, const int N, const int M){
    if(idx == M) return (ll)validA;
    ll& ans = memo[idx][tightA][tightB][validA];
    if(ans != -1) return ans;
    int limitA = tightA ? 0 : a[idx]-'0';
    int limitB = tightB ? 9 : b[idx]-'0';

    ans = 0;
    for(int i = limitA; i <= limitB ; ++i){
        int newTightA = tightA || (i > a[idx] - '0');
        int newTightB = tightB || (i < b[idx] - '0');
        int newValidA = validA || i>0;
        int factor = newValidA ? (ll)i : 1LL;
        ans = max(ans, factor * solve(idx+1, newTightA, newTightB, newValidA ,a, b, N, M));
    }
    return ans;
}

string numberAns;
void recover(int idx, bool tightA, bool tightB, bool validA, string& a, string& b, const int N, const int M){
    if(idx == M) return;
    ll& ans = memo[idx][tightA][tightB][validA];
    int limitA = tightA ? 0 : a[idx]-'0';
    int limitB = tightB ? 9 : b[idx]-'0';

    for(int i = limitA; i <= limitB ; ++i){
        int newTightA = tightA || (i > a[idx] - '0');
        int newTightB = tightB || (i < b[idx] - '0');
        int newValidA = validA || i>0;
        ll factor = newValidA ? (ll)i : 1LL;
        ll newans = factor * solve(idx+1, newTightA, newTightB, newValidA ,a, b, N, M);
        if(newans == ans){
            if(newValidA) numberAns+=(i+'0');
            recover(idx+1, newTightA, newTightB, newValidA ,a, b, N, M);
            break;
        }
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string a, b;
    cin >> a >> b;
    const int N = a.size();
    const int M = b.size();

    if(N < M) a.insert(0, M-N, '0');

    memset(memo, -1, sizeof(memo));
    solve(0,0,0,0,a,b,N,M);
    recover(0,0,0,0,a,b,N,M);

    cout << numberAns << endl;
    return 0;
}