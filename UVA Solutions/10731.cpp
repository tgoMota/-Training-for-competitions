//https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1672
//UVA 10731 - Test
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
vector<int> dfs_num, dfs_low, vst, st;
unordered_map<char, int> idx;
vector<char> name;
vector<vector<char>> ans;
const int MAX = 26;

void dfsTarjan(int v, int& dfsTime){
    dfs_num[v] = dfs_low[v] = ++dfsTime;
    st.push_back(v);
    vst[v] = 1;
    for(int x : adj[v]){
        if(!dfs_num[x]) dfsTarjan(x, dfsTime);
        if(vst[x]) dfs_low[v] = min(dfs_low[v], dfs_low[x]);
    }

    if(dfs_low[v] == dfs_num[v]){
        vector<char> a;
        while(1){
            int u = st.back();
            st.pop_back();
            vst[u] = 0;
            a.push_back(name[u]);
            if(u == v) break;
        }
        ans.push_back(a);
    }
}

int main(){
    int n, t = 0;
    while(scanf("%d", &n) && n){
        if(t++) printf("\n");
        adj.assign(MAX, vector<int>());
        dfs_num.assign(MAX, 0);
        dfs_low.assign(MAX, 0);
        st.clear();
        vst.assign(MAX, 0);
        name.resize(MAX);
        idx.clear();
        for(int i = 0; i < ans.size(); ++i) ans[i].clear();
        ans.clear();
        int cnt = 0;
        for(int i = 0; i < n ; ++i){
            vector<int> question;
            char c;
            for(int j = 0; j < 5 ; ++j){
                cin >> c;
                if(idx.find(c) == idx.end()) {
                    idx[c] = cnt, name[cnt] = c;
                    question.push_back(cnt++);
                }else question.push_back(idx[c]);
            }
            cin >> c;
            int u = idx[c]; //answer idx
            for(int x : question) adj[u].push_back(x);
        }
        const int V = idx.size();
        for(int i = 0; i < V ; ++i){
            if(!dfs_num[i]){
                int dfsTime = 0;
                dfsTarjan(i, dfsTime);
            }
        }
        for(int i = 0; i < ans.size(); ++i){
            sort(ans[i].begin(), ans[i].end());
        }
        sort(ans.begin(), ans.end());
        for(int i = 0; i < ans.size(); ++i){
            for(int j = 0; j < ans[i].size() ; ++j){
                if(j == 0) printf("%c", ans[i][j]);
                else printf(" %c", ans[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}