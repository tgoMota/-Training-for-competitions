//www.urionlinejudge.com.br/judge/pt/problems/view/1081
#include <bits/stdc++.h>
using namespace std;
int n, m, clk, dist[22], t, l, k;
bool vst[22];
set<int> adj[22];

void dfs(int v, int b){
    for(int x : adj[v]){
        if(vst[x]) {
            for(int i = 0; i < b ; ++i) printf(" ");
            printf("%d-%d\n", v, x);
            continue;
        }
        if(l!= 0 && k == 0){
            printf("\n");
            k = 1;
        }
        vst[x] = true;
        for(int i = 0; i < b ; ++i) printf(" ");
        printf("%d-%d pathR(G,%d)\n", v, x, x);
        dfs(x, b+2);
    }
}

int main(){
    cin >> t;
    while(t-->0 && cin >> n >> m){
        for(int i = 1; i <= m ; ++i){
            int a, b;
            cin >> a >> b;
            adj[a].insert(b);
        }
        cout << "Caso " << ++clk << ":\n"; 
        for(int i = 0; i < n ; ++i){
            k = 0;
            l = i;
            if(!vst[i]) {
                vst[i] = true;
                dfs(i, 2);
            }
        }
        printf("\n");
        for(int i = 0; i < n ; ++i) {
            adj[i].clear();
            vst[i] = false;
        }
    }

    return 0;
}
