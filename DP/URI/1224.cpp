#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
typedef long long ll;
int N;
const int M = 1005;
//map<pair<int,int>, ll> m;
ll memo[M][M];
ll solve(int left, int right, int turn, vector<int>& data){
    if(left > right) return 0LL;
    // auto k = m.find(make_pair(left,right));
    // if(k != m.end()) return (*k).second;
    // ll ans;
    ll& ans = memo[left][right];
    if(ans != -1) return ans;
    if(turn % 2 != 0) ans = max((ll) data[left] + solve(left+1, right, turn+1, data), (ll) data[right] + solve(left, right-1, turn+1, data));
    else ans = min(solve(left+1, right, turn+1, data), solve(left, right-1, turn+1, data));
    return ans;
}

int main(){
    vector<int> data;
    while(scanf("%d", &N) != EOF){
        data.assign(N,0);
        for(int& x : data) scanf("%d", &x);
       // m.clear();
        for(int i = 0; i < N ; ++i) for(int j = 0; j < N ; ++j) memo[i][j] = -1;
        printf("%lld\n", solve(0,N-1, 1, data));
    }
    return 0;
}