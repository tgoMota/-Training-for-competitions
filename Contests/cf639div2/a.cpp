#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
#define ooLL 0x3f3f3f3f3f3f3f3f
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL)
const int mod = 1e9+7;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
 
int main(){
    int t;
    scanf("%d", &t);
    for(int ti = 1; ti <= t ; ++ti){
        int n, m;
        scanf("%d%d", &n, &m);
        if(n == 1 || m == 1) printf("YES\n");
        else if(n == 2 && m == 2) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}