#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
#define ooLL 0x3f3f3f3f3f3f3f3f
#define fastio() ios_base::sync_with_stdio(false); cin.tie(0)
#define debug(x) cout << "DONT CRY " << x << endl
#define debug2(x,y) cout << "DONT CRY {" << x << "," << y << "}\n"
const int mod = 1e9+7;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int,int> ii;
 
int main(){
    int t;
    scanf("%d", &t);
    for(int ti = 1; ti <= t ; ++ti){
        int n;
        scanf("%d", &n);
        vector<int> v(n+1);
        vector<int> cnt(n+1, 0);
        vector<int> last(n+1, 0);
        for(int i = 1; i <= n ; ++i){
            scanf("%d", &v[i]);
            if(i - last[v[i]] > 1) cnt[v[i]]++;
            last[v[i]] = i; 
        }

        int ans = oo;
        for(int i = 1; i <= n ; ++i){
            ans = min(ans, cnt[v[i]]+(v[n] != v[i]));
        }

        printf("%d\n", ans);
    }
    return 0;
}