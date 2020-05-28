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
ll px, py, valx, nextx, nexty;
ll calc(int x, int y){
    px = 0, py = 0, valx = 0, nextx = 0, nexty = 0;
    int xi = 1, yi = 1;
    ll add = 2LL, valuex = 1LL;
    while(xi < x){
        valuex += add;
        add++;
        xi++;
    }
    px = xi;
    add = xi;
    nextx = add;
    while(yi < y){
        valuex += add;
        add++;
        nextx++;
        yi++;
    }
    nextx++;
    nexty = add;
    py = yi;
    valx = valuex;
}

struct square{
    ll nx, ny, px, py, val, sum;
    square(ll a, ll b, ll c, ll d, ll e, ll f){
        nx = a;
        ny = b;
        px = c;
        py = d;
        val = e;
        sum = f;
    }
};

int main(){
    int t;
    scanf("%d", &t);
    for(int ti = 1; ti <= t ; ++ti){
        int a, b, c, d;
        scanf("%d%d%d%d", &a, &b, &c, &d);
        int ans = 0;
        calc(a,b);
        queue<square> q;
        q.push(square(nextx, nexty,a,b,valx, valx));
        set<ll> ways;
        while(!q.empty()){
            auto x = q.front();
            q.pop();
            if(x.px > c || x.py > d) continue;
            if(x.px == c && x.py == d){
                ways.insert(x.sum);
            }

            q.push(square(x.nx+1, x.ny+1,x.px+1, x.py, x.val+x.nx, x.sum+x.val+x.nx));
            q.push(square(x.nx+1, x.ny+1,x.px, x.py+1, x.val+x.ny, x.sum+x.val+x.ny));
        }

        printf("%lld\n", (ll)ways.size());
    }
    return 0;
}