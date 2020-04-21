//https://www.urionlinejudge.com.br/judge/pt/problems/view/2403
//URI 2403 - Escalonamento Ótimo
#include <bits/stdc++.h>
using namespace std;
vector<int> result;
vector<vector<int>> adj;
vector<int> incomingEdges;

void kahn(const int N){
    set<int> next;
    for(int i = 0; i < N ; ++i){
        if(incomingEdges[i] == 0) next.insert(i);
    }
    result.clear();
    while(!next.empty()){
        int v = *next.begin();
        next.erase(next.begin());
        result.push_back(v);
        for(int i = 0; i < adj[v].size() ; ++i){
            if(--incomingEdges[adj[v][i]] == 0) next.insert(adj[v][i]);
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    adj.resize(n);
    incomingEdges.resize(n);
    for(int i = 0; i < m ; ++i){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        incomingEdges[b]++;
    }

    kahn(n);
    if((int)result.size() == n) for(int x : result) printf("%d\n", x);
    else printf("*\n");
    

    return 0;
}