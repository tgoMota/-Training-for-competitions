#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
#define ooLL 0x3f3f3f3f3f3f3f3f
#define mod 1e9+7
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
typedef long long ll;
typedef vector<pair<int,int>> vii;
typedef pair<int,int> pii;
map<int,int> g1;
 
int main(){
    int t;
    scanf("%d", &t);
    for(int ti = 1; ti <= t ; ++ti){
        int n;
        scanf("%d", &n);
        vector<int> v(n);
        for(int i= 0; i < n ; ++i) {
           scanf("%d", &v[i]);
           if(g1.find(v[i]) == g1.end()) g1[v[i]] = 1;
           else g1[v[i]]++;
        }
        int a = g1.size()-1, b = 0;
        for(auto x : g1) {
            b = max(b, x.second);
        }
        if(b > a+1) printf("%d\n", min(a+1,b));
        else printf("%d\n", min(a, b));
        g1.clear();
    }
    return 0;
}