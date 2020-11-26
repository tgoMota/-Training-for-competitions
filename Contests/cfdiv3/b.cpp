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
        vector<ii> cnt(n+1, {0,0});
        for(int i = 1; i <= n ; ++i){
            int a;
            scanf("%d", &a);
            cnt[a].first++;
            cnt[a].second = i;
        }
        int minx = -1;
        for(int i = 1; i <= n ; ++i){
            if(cnt[i].first == 1){
                minx = cnt[i].second;
                break;
            }
        }
        printf("%d\n", minx);
            
    }
    return 0;
}