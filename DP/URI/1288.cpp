#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        vector<pair<int,int>> v(n+1);
        for(int i = 1; i <= n ; ++i) {
            int a, b;
            scanf("%d%d", &a, &b);
            v[i] = make_pair(a, b);
        }
        int K, R;
        scanf("%d", &K);
        scanf("%d", &R);
        
        bool itsOk = false;
        vector<vector<int>> dp(n+1, vector<int>(K+1, 0));
        for(int id = 1; id <= n ; ++id){
            for(int cap = 0; cap <= K ; ++cap){
                if(v[id].second <= cap) dp[id][cap] = max(dp[id-1][cap], dp[id-1][cap-v[id].second]+v[id].first);
                else dp[id][cap] = dp[id-1][cap];
                if(dp[id][cap] >= R) {
                    itsOk = true;
                    break;
                }
            }
            if(itsOk) break; 
        }
        if(itsOk) printf("Missao completada com sucesso\n");
        else printf("Falha na missao\n");
    }
    return 0;
}