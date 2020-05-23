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
    multiset<int> ma;
    for(int ti = 1; ti <= t ; ++ti){
        ma.clear();
        int n, k;
        scanf("%d%d", &n, &k);
        for(int i = 0; i < n ; ++i){
            int a;
            scanf("%d", &a);
            ma.insert(a);
        }
        vector<int> mb(n);
        for(int i = 0; i < n ; ++i){
            scanf("%d", &mb[i]);
        }

        sort(mb.begin(), mb.end(), greater<int>());

        for(int x : mb){
            if(k <= 0) break;
            int a = *ma.begin();
            if(x > a){
                k--;
                ma.erase(ma.begin());
                ma.insert(x);
            }
        }

        ll sum = 0LL;
        for(int x : ma) sum+=x;
        printf("%lld\n", sum);
    }
    return 0;
}