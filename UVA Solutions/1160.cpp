//WRONG ..... WHYYY?
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef long long ll;
vector<int> parent;
vector<ii> edges;
int n;
void init(){
    parent.resize(n);
    for(int i = 0; i < n ; ++i) parent[i] = i;
}

int find(int u){
    return parent[u] == u ? parent[u] : find(parent[u]);
}

void merge(int x, int y){
    x = find(x), y = find(y);
    parent[y] = x;
}

int kruskal(){
    int cnt = 0;
    for(int i = 0; i < edges.size(); ++i){
        auto x = edges[i];
        int u = x.first;
        int v = x.second;

        if(find(u) == find(v)) continue;
        merge(u, v);
        ++cnt;
    }
    
    return (int)edges.size()-cnt;
}

void solve(){
    init();
    printf("%d\n", kruskal());
}

int main(){
    string s;
    while(getline(cin, s) && !cin.eof()){
        if(s == "") continue;
        if(s == "-1"){
            solve();
            cin.ignore();
            edges.clear();
            n = 0;
            continue;
        }
        string a = "", b = "";
        for(int i = 0; i < s.size() ; ++i){
            if(s[i] == ' ') a.swap(b);
            else a+=s[i];
        }
        int u = stoi(a) - 1;
        int v = stoi(b) - 1;
        n = max({n, u+1, v+1});
        if(u != v) edges.push_back({u,v});
    }
    return 0;
}