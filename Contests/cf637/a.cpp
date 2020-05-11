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
 
int main(){
    int t;
    scanf("%d", &t);
    for(int ti = 1; ti <= t ; ++ti){
        int n, a, b, c, d;
        cin >> n >> a >> b >> c >> d;
        
        bool ok = false;
        for(int i = c-d; i <= c+d ; ++i){
            int rest = i%n != 0;
            if(i/n >= a-b && i/n+rest <= a+b){
                ok = true;
                break;
            }
        }
 
        if(ok) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}