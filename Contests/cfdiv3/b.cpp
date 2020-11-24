#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
#define ooLL 0x3f3f3f3f3f3f3f3f
#define fastio() ios_base::sync_with_stdio(false); cin.tie(0)
#define debug(x) cout << "DONT CRY " << x << endl
#define debug2(x,y) cout << "DONT CRY {" << x << "," << y << "}\n"
const int mod = 1e9+7;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int,int> ii;
 
int main(){
    int t;
    scanf("%d", &t);
    for(int ti = 1; ti <= t ; ++ti){
        int n;
        scanf("%d", &n);
        vector<ii> v(n, {0,0});
        for(int i = 0; i < n ; ++i){
            scanf("%d", &v[i].first);
            v[i].second = i+1;
        }
        sort(v.begin(), v.end());
        pair<int,int> minx = {-1,-1};
        for(int i = 0; i < n-1 ; ++i){
            if(v[i].first == v[i+1].first){
                for(int j = i+1; j < n ; ++j){
                    if(v[j].first != v[i].first){
                        i = j-1;
                        break;
                    }
                }
            }else{
                minx = v[i];
                break;
            } 
        }

        if(minx.first == -1 && n>1 && v[n-1].first != v[n-2].first) minx = v.back();
        else if(n == 1) minx = v.back();
        printf("%d\n", minx.second);
    }
    return 0;
}