//https://www.urionlinejudge.com.br/judge/pt/problems/view/1549
//URI 1549 - Dividindo a Coca
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
typedef long double ld;
ld n, l, b, B, H, v, bm;
const ld EPS = 1e-10;
ld check(ld& mid){
    ld pa = (M_PI * mid)/3.0;
    ld r = ((mid*(B-b))/H)+(ld)b;
    ld pb = (r*r + r*b + b*b);
    return pa*pb;
}
int main(){
    int t;
    scanf("%d", &t);
    for(int ti = 1; ti <= t ; ++ti){
        scanf("%llf%llf%llf%llf%llf", &n, &l, &b, &B, &H);
        bm = B-b;
        v = l/n;
        ld lo = 0.0, hi = H, ans = 0.0;
        for(int i = 0; i < (int)1e4 ; ++i){
            ld mid = (lo+hi)*0.5;
            ld V = check(mid);
            if(abs(V-v) < EPS){ 
                ans = mid;
                break;
            }
            else if(V<v) lo = mid;
            else hi = mid;
        
        }
        printf("%.2llf\n", ans);
    }
    return 0;
}