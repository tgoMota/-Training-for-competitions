//https://onlinejudge.org/external/4/423.pdf
//UVA 423 MPI Maelstrom
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
const int maxN = 105;
ll adj[maxN][maxN];

int main(){
    fastio();
    int n;
    cin >> n;
    for(int i = 1; i <= n ; ++i) for(int j = 1; j <= n ; ++j) adj[i][j] = ooLL;
    adj[1][1] = 0LL;
    for(int i = 2; i <= n ; ++i){
        adj[i][i] = 0LL;
        for(int j = 1; j < i ; ++j){
            string x;
            cin >> x;
            if(x == "x") adj[i][j] = adj[j][i] = oo;
            else adj[i][j] = adj[j][i] = stoi(x);
        }
    }

    for(int k = 1; k <= n ; ++k){
        for(int i = 1; i <= n ; ++i){
            for(int j = 1; j <= n ; ++j){
                adj[i][j] = min(adj[i][j], adj[i][k]+adj[k][j]);
            }
        }
    }

    ll maxx = 0LL;
    for(int i = 1; i <= n ; ++i) if(adj[1][i] < ooLL) maxx = max(maxx, adj[1][i]);

    cout << maxx << '\n';
    return 0;
}