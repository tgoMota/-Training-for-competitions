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
        for(int i = 0; i < n ; ++i) scanf("%d", &v[i]);
        sort(v.begin(), v.end(), greater<int>());
        int mindif = oo;
        for(int i = 1; i < n ; ++i){
            mindif = min(mindif, abs(v[i]-v[i-1]));
        }
        printf("%d\n", mindif);
    }
    return 0;
}