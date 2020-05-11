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

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    vector<int> h(n+1);
    for(int i = 1; i <= n ; ++i) scanf("%d",&h[i]);

    vector<bool> v(n+1, true);
    for(int i = 0; i < m ; ++i){
        int a, b;
        scanf("%d%d", &a, &b);
        if(h[a] <= h[b]) v[a] = false;
        if(h[b] <= h[a]) v[b] = false;
    }
    int cnt = 0;
    for(int i = 1; i <= n ; ++i) if(v[i]) cnt++;

    printf("%d\n", cnt);
    return 0;
}