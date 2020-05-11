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
        int n;
        scanf("%d", &n);
        vector<int> v(n);
        unordered_map<int,int> m;
        for(int i = 0; i < n ; ++i) {
            scanf("%d", &v[i]);
        }
        bool ok = true;
        for(int i = 0; i < n ; ++i){
            int k = v[i];
            int r = k % n;
            int rn = k + v[r];
            printf("rn = %d\n", rn);
            if(((k-r) % n) == 0) m[rn]++;
            else m[k]++, rn = k;
            if(m[rn] > 1) ok = false;
        }

        if(ok) printf("YES\n");
        else printf("NO\n");
        printf("\n\n");
    }
    return 0;
}