#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
#define ooLL 0x3f3f3f3f3f3f3f3f
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL)
const int mod = 1e9+7;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> ii;
 
int main(){
    int t;
    scanf("%d", &t);
    for(int ti = 1; ti <= t ; ++ti){
        int n;
        scanf("%d", &n);
        vector<int> v(n+1);
        for(int i = 1; i <= n ; ++i) scanf("%d", &v[i]);
        vector<int> dp(n+1, 1);
        int ans = 1;
        for(int i = 1; i <= n ; ++i){
            for(int j = i; j <= n ; j+=i){
                if(v[j] > v[i]){
                    dp[j] = max(dp[j], dp[i]+1);
                    ans = max(ans, dp[j]);
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}