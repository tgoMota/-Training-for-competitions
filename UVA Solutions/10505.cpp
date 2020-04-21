//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1446
//10505 - Montesco vs Capuleto
#include <bits/stdc++.h>
using namespace std;

int adj[201][201]; //enemys
int check(int v, const int sz, vector<int>& color, int& ans){
    if(color[v] != -1) return 1;
    color[v] = 1;
    vector<int> amountColor(2, 0);
    amountColor[color[v]]++;

    queue<int> q;
    q.push(v);

    while(!q.empty()){
        int u = q.front();
        q.pop();

        if(adj[u][u] == 1) return 0;

        for(int i = 1; i <= sz ; ++i){
            if(adj[u][i] == -1) continue;
            if(color[i] == -1) {
                color[i] = 1 - color[u];
                amountColor[color[i]]++;
                q.push(i);
            }
            else if(color[i] == color[u]) return 0;
        }
    }

    ans += max(amountColor[0], amountColor[1]);
}

int main(){

    int T, n;
    scanf("%d", &T);
    while(T--){
        memset(adj, -1, sizeof(adj));
        scanf("%d", &n);
        for(int i = 1; i <= n ; ++i){
            scanf("%d", &adj[i][0]);
            for(int j = 0; j < adj[i][0] ; ++j){
                int a;
                scanf("%d", &a);
                adj[i][a] = adj[a][i] = 1;
            }
        }
        vector<int> colors(n+1, -1);
        int ans = 0;
        for(int i = 1; i <= n ; ++i) check(i, n, colors, ans);

        printf("%d\n", ans);
    }


    return 0;
}