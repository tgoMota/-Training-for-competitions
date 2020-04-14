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
vector<int> adj[501];
bool contain(vector<int> a, int b){
    for(int x : a) if(x == b) return true;
    return false;
}

bool vst[501];
unordered_map<int,int> isDead;
int dfs(int a){
    int ans = 0;
    for(int x : adj[a]){
        if(vst[x]) continue;
        vst[x] = true;
        if(isDead.find(x) != isDead.end()) ans+= dfs(x);
        else ans += 1+dfs(x);
    }
    return ans;
}

int main(){
    int N, M;
    cin >> N >> M;
    for(int i = 1; i <= M ; ++i){
        int a, b;
        cin >> a >> b;
        if(a == b) continue;
        if(!contain(adj[a], b)) adj[a].push_back(b);
        if(!contain(adj[b], a)) adj[b].push_back(a);
    }
    int x;
    cin >> x;
    for(int i = 1; i <= x ; ++i){
        int k;
        cin >> k;
        isDead[k] = 1;
    }
    vector<int> ans;
    int familys = 0;
    for(int i = 1; i <= N ; ++i){
        if(vst[i]) continue;
        vst[i] = true;
        int u = dfs(i);
        if(isDead.find(i) == isDead.end()) u++;
        if(u == 0) continue;
        familys++;
        ans.push_back(u);
    }
    sort(ans.begin(), ans.end());
    printf("Quantidade de familias: %d\n", familys);
    printf("Numero de habitantes em cada: ");
    for(int i = 0; i < ans.size() ; ++i){
        printf("%d", ans[i]);
        if((int)ans.size() > 1 && i < (int)ans.size() - 2) printf(", ");
        if(i == (int)ans.size() - 2) printf(" e ");
    }
    printf("\n");
    return 0;
}