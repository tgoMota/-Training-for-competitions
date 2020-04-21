//https://www.spoj.com/problems/SAMER08F/
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    while(scanf("%d", &n) && n){
        int ans = 0;
        for(int i = 1; i <= n ; ++i) ans+= pow((n-i)+1,2); 
        cout << ans << endl;
    }
    return 0;
}
