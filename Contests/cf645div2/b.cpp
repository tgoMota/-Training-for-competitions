#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
#define ooLL 0x3f3f3f3f3f3f3f3f
#define fastio() ios_base::sync_with_stdio(false); cin.tie(0)
#define debug(x) cout << "DONT CRY " << x << endl
#define debug2(x,y) cout << "DONT CRY {" << x << "," << y << "}\n"
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
        for(int& x : v) scanf("%d", &x);
        sort(v.begin(), v.end());
        // printf("v = ");
        // for(int x : v) printf("%d ", x);
        // printf("\n");
        int d = 1;
        for(int i = 0; i < n ; ++i){
            if(v[i] <= d) d++;
            else {
                int cnt = d;
                for(int j = i; j < n ; ++j){
                    if(++cnt > v[j]){
                        d = cnt;
                        i = j;
                        break;
                    }
                    if(j == n-1) i = n-1;
                }
            }
        }
        printf("%d\n", d);
    }
    return 0;
}