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
vector<int> v;
int main(){
    int t;
    scanf("%d", &t);
    for(int ti = 1; ti <= t ; ++ti){
        int n;
        scanf("%d", &n);
        v.assign(n, 0);
        int cnt = 0, lastOne = -1;
        for(int i = 0; i < n ; ++i) {
            scanf("%d", &v[i]);
            if(lastOne == -1 && v[i]) lastOne = i;
            else if(lastOne != -1 && v[i]) {
                cnt += (i-lastOne-1);
                lastOne = i;
            }
        }

        printf("%d\n", cnt);
    }
    return 0;
}