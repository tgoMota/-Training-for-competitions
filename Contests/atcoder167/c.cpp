#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
#define ooLL 0x3f3f3f3f3f3f3f3f
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL)
const int mod = 1e9+7;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> ii;
int n, m, x;

int main(){
    scanf("%d%d%d", &n, &m, &x);
    int grid[n][m], costs[n];
    for(int i = 0; i < n ; ++i){
        scanf("%d", &costs[i]);
        for(int j = 0; j < m ; ++j){
            scanf("%d", &grid[i][j]);
        }
    }

    int ans = oo;
    for(int i = 0; i < (1<<n) ; ++i){
        vector<int> s(m, 0);
        int cst = 0;
        for(int j = 0; j < n ; ++j){
            if(i & (1<<j)) continue;
            cst+=costs[j];
            for(int k = 0; k < m ; ++k) s[k]+=grid[j][k];
        }

        bool valid = true;
        for(int k = 0; k < m && valid; ++k){
            if(s[k] < x) valid = false;
        }
        if(valid) ans = min(ans, cst);
    }

    printf("%d\n", ans == oo ? -1 : ans);

    

    return 0;
}