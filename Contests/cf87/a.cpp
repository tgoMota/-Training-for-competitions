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
        ll a, b, c, d;
        scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
        //has sleep => a, first alarm goes off => b, next alarm => c, d => time to fall asleep
        if(b >= a){
            printf("%lld\n", b);
        }
        else if(d >= c && b < a){
            printf("-1\n");
        }else{
            ll r = a-b;
            printf("%lld\n", ((r-1)/(c-d)+1LL)*c + b);
        }
    }
    return 0;
}