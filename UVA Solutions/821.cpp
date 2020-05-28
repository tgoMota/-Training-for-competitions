//https://onlinejudge.org/external/8/821.pdf
//UVA 821 Page Hopping
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
int adj[maxN][maxN];
int main(){
    int a, b, ti = 0;
    while(scanf("%d%d", &a, &b) && a+b){
        for(int i = 0; i < maxN ; ++i) for(int j = 0; j < maxN ; ++j) adj[i][j] = oo;
        adj[a][b] = 1;
        while(scanf("%d%d", &a, &b) && a+b) adj[a][b] = 1;
        
        for(int k = 1; k < maxN ; ++k){
            for(int i = 1; i < maxN ; ++i){
                for(int j = 1; j < maxN ; ++j){
                    adj[i][j] = min(adj[i][j], adj[i][k]+adj[k][j]);
                }
            }
        }

        ll sum = 0LL;
        int cnt = 0;
        for(int i = 1; i < maxN ; ++i){
            for(int j = 1; j < maxN ; ++j){
                if(i!=j && adj[i][j] < oo) sum += adj[i][j], cnt++;
            }
        }
        printf("Case %d: average length between pages = %.3lf clicks\n", ++ti, sum/double(cnt));
    }
    return 0;
}