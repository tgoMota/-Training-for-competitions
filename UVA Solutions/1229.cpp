//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3670
//UVA 1229 - Sub-dictionary
#include <bits/stdc++.h>
using namespace std;
map<string, int> idx;
vector<string> word;
vector<vector<int>> adj;
vector<vector<int>> ans;
vector<int> dfs_num, dfs_low, vst, st;
vector<string> finalAns;

void dfs(int v, int& dfsTime){
    dfs_num[v] = dfs_low[v] = ++dfsTime;
    st.push_back(v);
    vst[v] = 1;
    for(int x : adj[v]){
        if(!dfs_num[x]) dfs(x, dfsTime);
        if(vst[x]) dfs_low[v] = min(dfs_low[v], dfs_low[x]);
    }

    if(dfs_low[v] == dfs_num[v]){
        vector<int> ans_cpy;
        while(1){
            int x = st.back();
            st.pop_back();
            vst[x] = 0;
            ans_cpy.push_back(x);
            if(x == v) break;
        }
        ans.push_back(ans_cpy);
    }
}

void rec(int v){
    if(vst[v]) return;
    vst[v] = 1;
    finalAns.push_back(word[v]);
    for(int x : adj[v]){
         rec(x);
    }
}

bool exist(vector<int>& a, int u){
    for(int x : a) if(x == u) return true;
    return false;
}

int main(){
    int n;
    while(scanf("%d", &n) && n){
        idx.clear();
        word.resize(n);
        dfs_low.assign(n, 0);
        dfs_num.assign(n, 0);
        vst.assign(n, 0);
        st.clear();
        adj.assign(n, vector<int>());
        for(int i = 0; i < ans.size() ; ++i) ans[i].clear();
        ans.clear();
        cin.ignore();

        string line;
        int cnt = 0;
        for(int i = 0; i < n ; ++i){
            getline(cin, line);
            int last = 0;
            vector<string> line2(31, "");
            for(int j = 0; j < line.size(); ++j){
                if(line[j] != ' ') line2[last] += line[j];
                else last++;
            }
            int m = last+1, u, v, k;
            for(int j = 0; j < m ; ++j){
                if(idx.find(line2[j]) == idx.end()){
                    idx[line2[j]] = cnt, word[cnt] = line2[j], k = cnt++;
                }else{
                    k = idx[line2[j]];
                }

                if(j == 0) {
                    u = k;
                    continue;
                }
                else v = k;

                if(!exist(adj[u], v)) adj[u].push_back(v);
            }
        }

        for(int i = 0; i < n ; ++i){
            if(!dfs_num[i]){
                int dfsTime = 0;
                dfs(i, dfsTime);
            }
        }
        
        finalAns.clear();
        vst.assign(n, 0);
        for(int i = 0; i < ans.size(); ++i){
            if((int)ans[i].size() > 1) rec(ans[i][0]);
        }

        sort(finalAns.begin(), finalAns.end());
        printf("%d\n", (int)finalAns.size());
        for(int i = 0; i < finalAns.size(); ++i){
            if(i == 0) printf("%s", finalAns[i].c_str());
            else printf(" %s", finalAns[i].c_str());
        }
        printf("\n");
    }
    return 0;
}