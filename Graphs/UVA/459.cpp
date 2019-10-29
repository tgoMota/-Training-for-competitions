//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=0&problem=400&mosmsg=Submission+received+with+ID+24110084
//UVA 459 - Graph Connectivity
#include <bits/stdc++.h>
using namespace std;

void dfs(int v, const vector<vector<int> >& adj, vector<bool>& vst, const int n){
    for(int x : adj[v]){
        if(vst[x]) continue;
        vst[x] = true;
        dfs(x, adj, vst, n);
    }
}

int main(){
    int nc;
    cin >> nc;
    while(nc--){
        char c;
        cin >> c;
        int n = c-'A'+1;
        string s;
        cin.ignore();
        vector<vector<int>> adj(n);
        vector<bool>vst(n, false);

        while(getline(cin,s) && s!=""){
            int a = s[0]-'A', b = s[1] - 'A';
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        int ncc = 0;
        for(int i = 0; i < n ; ++i){
            if(!vst[i]){
                ++ncc;
                dfs(i, adj, vst, n);
            }
        }
        printf("%d\n", ncc);
        if(nc) {
            for(int i = 0; i < n ; ++i) adj[i].clear();
            printf("\n");    
        }
    }

    return 0;
}