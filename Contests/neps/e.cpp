#include <bits/stdc++.h>
using namespace std;
#define oo = 0x3f3f3f3f;
typedef long long ll;

int main(){
    int n;
    cin >> n;
    int ans;
    if(n > 9) ans = n-9;
    else ans = 24 - (9-n);
    if(ans == 24) ans = 0;
    printf("%d\n", ans);
    return 0;
}