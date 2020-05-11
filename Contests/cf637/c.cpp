#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
#define ooLL 0x3f3f3f3f3f3f3f3f
#define mod 1e9+7
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
typedef long long ll;
typedef vector<pair<int,int>> vii;
typedef pair<int,int> pii;
const int M = 200005;
vector<int> adj[M];
multiset<int, greater<int>> s;
vector<bool> vst;
void dfs(int v, int height){
    s.insert(height);
    if((int)adj[v].size() == 0){
        return; 
    }
    vst[v] = true;
    for(int x : adj[v]){
        if(vst[x]) continue; 
        dfs(x, height+1);
    }
}

int main(){
        int n, k;
        scanf("%d%d", &n, &k);
        for(int i = 1; i <= n-1 ; ++i){
            int a, b;
            scanf("%d%d", &a, &b);
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        vst.assign(n+1, false);
        dfs(1,0);
        int index = 0;
        int ans = 0;
        for(auto x : s){
            if(index == k) break;
            ans+= *s.begin();
           // printf("%d ", *s.begin());
            s.erase(s.begin());
            index++;
        }

        printf("%d\n", ans);
        
    return 0;
}