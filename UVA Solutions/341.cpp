//https://onlinejudge.org/external/3/341.pdf
//UVA 341 Non-Stop Travel
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
int n;
int adj[11][11];
int parent[11][11];
void printPath(int o, int d){
    if(o!=d) printPath(o, parent[o][d]);
    printf(" %d", d);
}

int main(){
    int ti = 0;
    while(scanf("%d", &n) && n){
        for(int i = 1; i <= n ; ++i) for(int j = 1; j <= n ; ++j) adj[i][j] = oo, parent[i][j] = i;
        for(int i = 1; i <= n ; ++i){
            int m;
            scanf("%d", &m);
            for(int j = 0; j < m ; ++j){
                int a, b;
                scanf("%d%d", &a, &b);
                adj[i][a] = b;
            }
        }

        int o, d;
        scanf("%d%d", &o, &d);
        for(int k = 1; k <= n ; ++k){
            for(int i = 1; i <= n ; ++i){
                for(int j = 1; j <= n ; ++j){
                    if(adj[i][k] + adj[k][j] < adj[i][j]) {
                        adj[i][j] = min(adj[i][j],adj[i][k] + adj[k][j]);
                        parent[i][j] = parent[k][j];
                    }
                }
            }
        }

        printf("Case %d: Path =", ++ti);
        printPath(o,d);
        printf("; %d second delay\n", adj[o][d]);

    }
    return 0;
}