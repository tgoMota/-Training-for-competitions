#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
#define ooLL 0x3f3f3f3f3f3f3f3f
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL)
const int mod = 1e9+7;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<pair<int,int>> vii;
typedef pair<int,int> pii;

double calc(ll mid, ll x){
    double c = pow(1.01, mid)*100;
    return pow(1.01, mid)*100LL >= x;
}

int main(){
    int n, k;
    scanf("%d%d",&n, &k);
    vector<bool> v(n+1);
    for(int i = 0; i < k ; ++i){
        int d;
        scanf("%d", &d);
        for(int i = 0; i < d ; ++i){
            int a;
            scanf("%d", &a);
            v[a] = true;
        }
    }
    int cnt = 0;
    for(int i = 1; i <= n ; ++i) if(!v[i]) cnt++;
    printf("%d\n", cnt);
    return 0;
}