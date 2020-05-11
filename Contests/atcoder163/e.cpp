#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
#define ooLL 0x3f3f3f3f3f3f3f3f
#define mod 1e9+7
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
typedef long long ll;
typedef vector<pair<int,int>> vii;
typedef pair<int,int> pii;
typedef pair<int,pii> ppii;
vector<vector<ppii>> adj;
vector<pii> costs;
int n, m, s;

// int solve(int idx, ){

// }

int main(){
    scanf("%d%d%d", &n, &m, &s);
    adj.assign(n, vector<ppii>());
    for(int i = 0; i < m ; ++i){
        int a, b, c, d;
        a--, b--;
        adj[a].push_back({b, {c,d}});
        adj[b].push_back({a, {c,d}});
    }

    for(int i = 0; i < n ; ++i){
        int a, b;
        scanf("%d%d", a, b);
        costs.push_back({a,b});
    }

    memset(memo, -1, sizeof(memo));
    printf("%d\n", solve());


    return 0;
}