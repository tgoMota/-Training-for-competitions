#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
#define ooLL 0x3f3f3f3f3f3f3f3f
#define mod 1e9+7
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
typedef long long ll;
typedef vector<pair<int,int>> vii;
typedef pair<int,int> pii;
const int M = 100005;
int memo[M][31]; 

int solve(int hp, int vd, int lg){
    if(vd < 0 || lg < 0) return 0;
    if(hp<= 0) return 1;
    int& ans = memo[hp][vd];
    if(ans != -1) return ans;
    int hpvoid = hp/2 + 10;
    int hplight = hp-10;
    return ans = solve(hpvoid, vd-1, lg) || solve(hplight, vd, lg-1);
}

int main(){
    int t;
    scanf("%d", &t);
    for(int ti = 1; ti <= t ; ++ti){
        int x, n, m; //Void // Light
        scanf("%d%d%d", &x, &n,&m);
        memset(memo, -1,sizeof(memo));
        if(solve(x,n,m)) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}