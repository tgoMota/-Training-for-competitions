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
    ll x;
    ll A, B;
    scanf("%lld", &x);
    bool neg = false;
    for(A = 0LL; A < 1000 ; ++A){
        bool ok = false;
        for(B = 0LL; B < 1000 ; ++B){
            if(pow(A,5)-pow(B,5LL) == x){
                ok = true;
                break;
            }
            if(pow(A,5LL)- pow(-B,5LL) == x){
                ok = true;
                B = -B;
                break;
            }

        }
        if(ok) break;
    }

    printf("%lld %lld\n", max(A,B), min(A,B));
    return 0;
}