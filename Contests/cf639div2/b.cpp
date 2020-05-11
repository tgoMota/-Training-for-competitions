#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
#define ooLL 0x3f3f3f3f3f3f3f3f
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL)
const int mod = 1e9+7;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
 
int calc(int N){
   ll cards = 0, h = 0;
   int ans = 0;
   while(N >= 2){
        cards = 0LL, h = 0LL;
        while(1){
            h++;
            if(cards + 2*h > N) break;
            cards += 2*h;
            ll newh = h+1;
            if(cards + h + (2*newh) > N) break;
            cards += h;
        }
        if(!cards) break;
        ans++;
        N -= cards;
   }
    return ans;
}

int main(){
    int t;
    scanf("%d", &t);
    for(int ti = 1; ti <= t ; ++ti){
        int n;
        scanf("%d", &n);
        printf("%d\n", calc(n));
    }
    return 0;
}