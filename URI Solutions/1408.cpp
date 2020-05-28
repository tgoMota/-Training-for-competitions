//https://www.urionlinejudge.com.br/judge/pt/problems/view/1408
//URI 1408 Mário
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
    int n, l;
    while(scanf("%d%d", &l, &n) && n+l){
        vector<int> v(n);
        for(int& x : v) scanf("%d", &x);
        int ans = oo;
        for(int i = 0; i < n ; ++i){
            int goal = v[i]+l-1;
            int longest = upper_bound(v.begin(), v.end(), goal)-v.begin();
            ans = min(ans, max(0, l+i-longest));
        }
        printf("%d\n", ans);
    }

    return 0;
}