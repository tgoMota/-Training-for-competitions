//https://www.urionlinejudge.com.br/judge/pt/problems/view/1835
#include <bits/stdc++.h>
using namespace std;

vector<int> adj[110];
int n,m, ans, clk;
bool vst[102];

void dfs(int v){
    for(int x:adj[v]){
        if(vst[x]) continue;
        vst[x] = true;
        dfs(x);
    }
}

int main(){

    int t;
    cin >> t;
    while(t-->0){
       cin >> n >> m;
        for(int i = 0; i < m ; ++i){
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        for(int i = 1; i <= n ; ++i){
            vst[i] = true;
            dfs(i);
            for(int j = 2; j<=n ; ++j){
                if(!vst[j]){
                    i = j-1;
                    ans++;
                    break;
                }
            }
        }

        cout << "Caso #" << ++clk;
        if(ans == 0) cout << ": a promessa foi cumprida\n";
        else cout << ": ainda falta(m) " << ans << " estrada(s)\n";
        for(int i = 1; i < 102 ; ++i) adj[i].clear();
        memset(vst, false, sizeof(vst));
        ans = 0;
    }

    return 0;
}