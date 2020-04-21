//https://codeforces.com/contest/4/problem/B
#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f

int d, sum, minT[100], maxT[100], memo[100][242], res[100];
 
int pd(int s, int n){
    if(s == 0 && n == 0) 
        return 0;
    if(s < 0 || n <= 0) return oo;
    int& ans = memo[n][s];
    if(ans != -1) return ans;
    ans = oo;
    for(int i = minT[n]; i <= maxT[n] ; ++i)
        ans = min(ans, i + pd(s-i,n-1));
    return ans;
}
 
void recover(int s, int n){
    if(s == 0) return;
    for(int i = minT[n]; i <= maxT[n] ; ++i){
        if(pd(s-i, n-1) == s-i){
            res[n] = i;
            recover(s-i,n-1);
            break;
        }
    }
}
 
int main(){
    cin >> d >> sum;
    memset(memo, -1, sizeof(memo));
    for(int i = 1; i <= d; ++i) cin >> minT[i] >> maxT[i];
    int la = pd(sum,d);
    la = la != sum? -1 : la;
    if(la == -1){
        printf("NO\n");
        return 0;
    }
    printf("YES\n");
    recover(sum, d);
    for(int i = 1; i <= d ; ++i){
        if(res[i] == -1) res[i] = 0;
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}