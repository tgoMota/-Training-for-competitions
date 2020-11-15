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
    int n;
    vector<int> v;
    while(scanf("%d", &n) && n){
        v.assign(n, 0);
        for(int& x : v) scanf("%d", &x);
        int ans = 0, timeB = -1;
        for(int i = 0; i < n ; ++i){
            //15 20 29 31 50
            if(timeB == -1) timeB = v[i];
            else if(v[i] - timeB <= 10) ans+= v[i]-timeB;
            else {
                ans+=10;
                timeB = -1;
                continue;
            }
            timeB = v[i];
        }
        printf("%d\n", ans+10);
    }
    return 0;
}