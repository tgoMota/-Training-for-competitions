//Wrong Answer
#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
#define ooLL 0x3f3f3f3f3f3f3f3f
#define fastio() ios_base::sync_with_stdio(false); cin.tie(0)
 
int main(){
    int n, k;
    scanf("%d%d", &n, &k);
    vector<int> v;
    int ans = 0;
    for(int i = 0; i < n ; ++i){
      int a;
      scanf("%d", &a);
      if(a > k){
        int div = a/k;
        if(div % 2 != 0) ans^=k;
        ans ^= (a%k);
      }else ans ^= a;
    }

    if(ans == 0) printf("Dila\n");
    else printf("Dali\n");
    return 0;
}
