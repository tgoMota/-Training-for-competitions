//http://codeforces.com/problemset/problem/623/A
//A. Graph and String
#include <bits/stdc++.h>
using namespace std;

int n, m;
string ans;
bool vst[502], nop;
char tab[502], c = 'a';
vector<int> adj[502];

void dfs(int v){
    tab[v] = c;
    if(adj[v].size() == n-1) {
        tab[v] = 'b';
        if(c == 'a') c = 'c';
        else c = 'a';
    }
    for(int x : adj[v]){
        if(vst[x]) continue;
        vst[x] = true;
        dfs(x);
    }
}

int main(){
    cin >> n >> m;
    for(int i = 1; i <= m ; ++i){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i = 1; i <= n ; ++i){
       if(!vst[i]) {
           dfs(i); 
            if(c == 'a') c = 'c';
            else c = 'a';
        }
       ans += tab[i];
       for(int x : adj[i]){
        if(abs(tab[i] - tab[x])>1){
            nop = true;
            cout << "No\n";
            break;
        }
       }
    }
 if(!nop) cout << "Yes\n" << ans << endl;
    return 0;
}