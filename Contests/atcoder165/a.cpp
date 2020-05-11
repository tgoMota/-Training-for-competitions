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
    int k, a, b;
    scanf("%d%d%d", &k, &a, &b);
    bool ok = false;
    for(int i = a; i <= b ; ++i) if(i % k == 0) ok = true;
    if(ok) printf("OK\n");
    else printf("NG\n");
    return 0;
}