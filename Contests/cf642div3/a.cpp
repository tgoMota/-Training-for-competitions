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
        ll n, m;
        scanf("%lld%lld", &n, &m);
        if(n == 1) printf("0\n");
        else if(n == 2) printf("%lld\n", m);
        else printf("%lld\n", 2*m);
    }
    return 0;
}