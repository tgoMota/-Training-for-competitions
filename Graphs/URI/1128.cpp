//https://www.urionlinejudge.com.br/judge/pt/problems/view/1128
#include <bits/stdc++.h>
using namespace std;
vector<int> adj[2002];
int n, m, ans;
bool vst[2002];

void bfs(int v){
    for(int i = 1; i <= n ; ++i) vst[i] = false;
    vst[v] = true;
    queue<int> fila;
    fila.push(v);
    int aux;
    ans = 1;
    while(!fila.empty()){
        aux = fila.front();
        fila.pop();
        for(int x : adj[aux]){
            if(vst[x]) continue;
            vst[x] = true;
            fila.push(x);
            ++ans;
        }
    }
}

int main(){
    while(scanf("%d%d", &n, &m)){
        if(n == 0 && m == 0) break;
        for(int i = 1; i <= m ; ++i){
            int a, b, c;
            cin >> a >> b >> c;
            adj[a].push_back(b);
            if(c == 2) adj[b].push_back(a);
        }
        int cont = 1;
        for(int i = 1; i <= n && cont ; ++i){
            bfs(i);
            if(ans != n) cont = 0;
        }
        cout << cont << endl;
        for(int i = 1; i <= n ; ++i) adj[i].clear();
    }
return 0;
}
