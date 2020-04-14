#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
#define ooLL 0x3f3f3f3f3f3f3f3f
#define mod 1e9+7
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
typedef long long ll;
typedef vector<pair<int,int>> vii;
    //ptotal = pm+pb+pg;
    //pm == pb
    //pg = ptotal - (pm+pb)
    //pg = ptotal - 2pm
    //ptotal = pg+2pm
    //K = 2PM
    //ptotal = pg+K
vector<int> v;
ll can(){
    ll bills = 0LL, majin = 0LL, maxsum = 0LL;
    for(int i = 0, j = v.size()-1; i <= j;){
        if(bills == majin) {
            maxsum = bills;
        }
        if(bills >= majin){
            majin+=v[j];
            j--;
        }else if(bills < majin){
            bills+=v[i];
            i++;
        }
    }
    if(bills == majin) maxsum = bills;
    return maxsum;
}

int main(){
    int n;
    cin >> n;
    v.assign(n, 0);
    for(int i = 0; i < n ; ++i) cin >> v[i];
    printf("%lld\n", can());
    return 0;
}