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
    int n;
    ll k;
    scanf("%d%llu", &n, &k);
    vector<int> v(n+1);
    for(int i = 1; i <= n ; ++i){
        scanf("%d", &v[i]);
    }
    int pos = 1, ntimes = 0;
    vector<int> freq(n+1, -1);
    while(k > 0){
        pos = v[pos];
        k--, ntimes++;
        if(freq[pos] != -1) k = (k % (ntimes-freq[pos]));
        freq[pos] = ntimes;
    }
    printf("%d\n", pos);
    return 0;
}