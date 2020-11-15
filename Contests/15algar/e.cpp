#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
#define ooLL 0x3f3f3f3f3f3f3f3f
#define fastio() ios_base::sync_with_stdio(false); cin.tie(0)
#define debug(x) cout << "DONT CRY " << x << endl
#define debug2(x,y) cout << "DONT CRY {" << x << "," << y << "}\n"
const int mod = 1e9+7;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int,int> ii;
vector<int> si, sr;
vector<vector<int>> lv;

int memo[1050][1050];
bool has(const int p, const int mask, const int N, const int M){
    for(int& x : lv[p]){
        if(!(mask & (1<< (x-1)))) return false; //x has to be took before
    }
    return true;
}
int solve(int p, int s, int mask, const int N, const int M){
    if(s <= si[p] || !has(p, mask, N, M)) return 0; //preciso passar pelos postos com linha de visao neste antes;
    if(mask == ((1<<N)-1)) return 1;
    int& ans = memo[s][mask];
    if(ans != -1) return ans;
    ans = 0;
    for(int i = 1; i <= N ; ++i){
        if((mask & (1<<(i-1)))) continue; //already visited
        ans |= solve(i, s+sr[p], mask | (1<<(p-1)), N, M);
    }
    return ans;
}
int main(){
    int n, m, s;
    while(scanf("%d%d%d", &n, &m, &s) && n+m+s){
        si.assign(n+1, 0);
        sr.assign(n+1, 0);
        lv.assign(n+1, vector<int>());
        for(int i = 1; i <= n ; ++i) scanf("%d", &si[i]);
        for(int i = 1; i <= n ; ++i) scanf("%d", &sr[i]);
        for(int i = 0; i < m ; ++i) {
            int a, b;
            scanf("%d%d", &a, &b);
            lv[b].push_back(a);
        }
        int ans = 0;
        for(int i = 1; i <= n ; ++i){
            memset(memo, -1, sizeof(memo));
            ans |= solve(i, s, 1<<(i-1), n, m);
        }
        printf("%s\n", ans? "possivel" : "impossivel");
    }

    return 0;
}