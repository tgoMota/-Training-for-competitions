//https://www.urionlinejudge.com.br/judge/pt/problems/view/1910
//URI 1910 Ajude Clotilde
#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
#define ooLL 0x3f3f3f3f3f3f3f3f
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL)
const int mod = 1e9+7;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> ii;

unordered_map<int,bool> isForbidden;
int main(){
    int o, d, k;
    while(scanf("%d%d%d", &o, &d, &k) && o+d+k){
        isForbidden.clear();
        for(int i = 0; i < k ; ++i){
            int a;
            scanf("%d", &a);
            isForbidden[a] = true;
        }
        vector<bool> vst(100005,false);
        queue<ii> q;
        q.push({o,0});
        int ans = -1;
        while(!q.empty()){
            auto x = q.front();
            int v = x.first;
            int w = x.second;
            q.pop();
            if(v <= 0 || v > 100000 || vst[v] || isForbidden[v]) continue;
            vst[v] = true;
            if(v == d) {
                ans = w;
                break;
            }
            q.push({v-1, w+1});
            q.push({v+1, w+1});
            q.push({v*2, w+1});
            q.push({v*3, w+1});
            if(v % 2 == 0) q.push({v/2, w+1});
        }

        printf("%d\n", ans);
    }
    return 0;
}