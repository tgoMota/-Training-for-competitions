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
    int t;
    scanf("%d", &t);
    for(int ti = 1; ti <= t ; ++ti){
        int n;
        scanf("%d", &n);
        vector<int> v(n);
        multiset<int> even, odd;
        for(int i = 0; i < n ; ++i) {
            scanf("%d", &v[i]);
            if(v[i] % 2 == 0) even.insert(v[i]);
            else odd.insert(v[i]);
        }
        sort(v.begin(), v.end());
        bool ok = false;
        for(int i = 1; i < n ; ++i) if(v[i]-v[i-1] == 1) ok = true;
        const int N = even.size(), M = odd.size();
        if(N%2 == 0 && M%2 == 0) printf("YES\n");
        else if(N%2 && M%2 && ok) printf("YES\n");
        else printf("NO\n");

    }
    return 0;
}