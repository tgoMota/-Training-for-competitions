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
        int n, k;
        scanf("%d%d", &n, &k);
        vector<int> v(n);
        for(int i = 0; i < n ; ++i) scanf("%d", &v[i]);
        map<int,int> cnt;
        for(int i = 0; i < n/2 ; ++i) cnt[v[i] + v[n-i-1]]++;
        pair<int,int> mx = *cnt.begin();
        for(auto x : cnt) {
            if(x.second > mx.second) mx = x;
            else if(x.second == mx.second && x.first > mx.first) mx = x;
        }
        int ans = 0;
        //printf("mx = {%d,%d}\n", mx.first, mx.second);
        for(int i = 0; i < n/2 ; ++i){
            if(v[i] + v[n-i-1] == mx.first) continue;
            int l = 0;
            if(v[i] >= mx.first) ans++, l++;
            if(v[n-i-1] >= mx.first) ans++, l++;
            if(l == 0){
                if(v[i]+k >= mx.first) ans++;
                else if(v[n-i-1]+k >= mx.first) ans++;
                else ans+=2;
            }
        }

        int ans2 = 0;
        for(int i = 0; i < n/2 ; ++i){
            if(v[i] + v[n-i-1] == k) continue;
            if(v[i] == k && v[n-i-1] == k) ans2+=2;
            else ans2++;
            
        }
        
        printf("%d\n", min(ans, ans2));
    }
    return 0;
}