#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
#define ooLL 0x3f3f3f3f3f3f3f3f
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL)
const int mod = 1e9+7;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> ii;
 
vector<int> v;
int main(){
    int t;
    scanf("%d", &t);
    for(int ti = 1; ti <= t ; ++ti){
        int n;
        scanf("%d", &n);
        v.reserve(n);
        multiset<int> m;
        for(int i = 0; i < n ; ++i){
            scanf("%d", &v[i]);
            m.insert(v[i]);
        }
        // 1 2 2 2 3
        int cnt = 0, ans = 0, mx;
        while(!m.empty()){
            mx = *m.begin();
            m.erase(m.begin());
            if(++cnt == mx){
                ans++;
                cnt = 0;
            }
        }
        printf("%d\n", ans);

    }
    return 0;
}