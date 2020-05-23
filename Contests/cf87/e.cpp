#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
#define ooLL 0x3f3f3f3f3f3f3f3f
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL)
const int mod = 1e9+7;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> ii;
vector<int> ncolor;


int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    ncolor.resize(3);
    scanf("%d%d%d", &ncolor[0], &ncolor[1], &ncolor[2]);
    vector<int> adj[n+1];
    for(int i = 0; i < m ; ++i){
        int u, v;
        scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    queue<int> q;
    q.push(1);
    vector<int> color(n+1, -1);
    color[1] = 0;
    return 0;
}