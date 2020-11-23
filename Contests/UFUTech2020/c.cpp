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
double n, l, b, B, H, v, bm;
const long double EPS = 1e-10;
double check(double& mid){
    double pa = (M_PI * mid)/3.0;
    double r = pow(v * 3.0 * (B - b)/ (M_PI  * H) + b * b * b, 1.0 / 3.0);
    double pb = (r*r + r*b + b*b);
    return pa*pb;
}
int main(){
    int t;
    scanf("%d", &t);
    for(int ti = 1; ti <= t ; ++ti){
        //Vtronco = ((pi*h)/3)*(R^2 + R*r + r*r)
        scanf("%lf%lf%lf%lf%lf", &n, &l, &b, &B, &H);
        bm = B-b;
        v = l/n;
        double lo = 0.0, hi = v, ans = 0.0;
        for(int i = 0; i < (int)1e4 ; ++i){
            double mid = (lo+hi)/2.0;
            double V = check(mid);
            if((V+EPS > v) && (v+EPS > V)){ 
                ans = mid;
                break;
            }
            else if(V<v) lo = mid;
            else hi = mid;
        
        }
        printf("%.2lf\n", ans);
    }
    return 0;
}