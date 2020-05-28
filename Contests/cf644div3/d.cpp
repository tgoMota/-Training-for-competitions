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
        int n, k;
        scanf("%d%d", &n, &k);
        int ans = oo;
        for(int i = 1; i*i <= n ; ++i){
            if(n%i == 0){
                if(n/i <= k) ans = min(ans, i);
                if(i <= k) ans = min(ans, n/i);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}