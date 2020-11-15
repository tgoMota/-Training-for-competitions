#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
#define ooLL 0x3f3f3f3f3f3f3f3f
#define fastio() ios_base::sync_with_stdio(false); cin.tie(0)
#define debug(x) cout << "DONT CRY " << x << endl
#define debug2(x,y) cout << "DONT CRY {" << x << "," << y << "}\n"
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
        vector<int> v(n+1, 0);
        int mx = 0;
        for(int i = 1; i <= n ; ++i){
            scanf("%d", &v[i]);
            mx = max(mx, v[i]);
        }
        int ans = -1;
        for(int i = 1; i <= n ; ++i){
            if(v[i] != mx) continue;
            else if(i > 1 && v[i-1] < mx) ans = i;
            else if(i < n && v[i+1] < mx) ans = i;
        }

        printf("%d\n", ans);
    }
    return 0;
}