//https://www.urionlinejudge.com.br/judge/pt/problems/view/1082
//URI 1082 Componentes Conexos
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
int n, e;
vector<vector<int>> adj;
vector<bool> vst;
vector<int> ans;
void dfs(int u){
    if(vst[u]) return;
    vst[u] = true;
    ans.push_back(u);
    for(int x : adj[u]){
        dfs(x);
    }
}

int main(){
    int t;
    scanf("%d", &t);
    for(int ti = 1; ti <= t ; ++ti){
        scanf("%d%d", &n, &e);
        adj.assign(n+1, vector<int>());
        for(int i = 0; i < e ; ++i){
            char aa[2], bb[2];
            scanf("%s%s", &aa, &bb);
            int a = aa[0]-'a', b = bb[0]-'a';
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        printf("Case #%d:\n", ti);
        vst.assign(n, false);
        int cnt = 0;
        for(int i = 0; i < n ; ++i){
            if(!vst[i]){
                cnt++;
                dfs(i);
                sort(ans.begin(), ans.end());
                for(int x : ans) printf("%c,", 'a'+x);
                printf("\n");
                ans.clear();
            }
        }
        printf("%d connected components\n\n", cnt);
    }
    return 0;
}