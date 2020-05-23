//https://codeforces.com/gym/102157/problem/1
//1. Nuclear Reactor
#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
const int m = 1e5+5;
ll p[m];
int n, k;
 
void print(ll ans){
    ll plants = 0LL;
    int react = 1;
    printf("%llu", p[0]);
    for(int i = 1; i < n ; ++i){
        plants += (p[i]-p[i-1]);
        if(plants >= ans){
            plants = 0LL;
            printf(" %llu", p[i]);
            react++;
            if(react >= k) break;
        }
    }
    printf("\n");
}
 
bool can(ll mid){
    ll plants = 0LL;
    int react = 1;
    for(int i = 1; i < n ; ++i){
        plants += (p[i]-p[i-1]);
        if(plants >= mid){
            plants = 0LL;
            react++;
        }
    }
    return react>=k;
}
 
int main(){
    cin >> n >> k;
    for(int i = 0 ; i < n ; ++i) cin >> p[i];
    sort(p,p+n);
 
    ll hi = 1e18, lo = 0LL, mid, ans = 0LL;
    for(int i = 0; i < 80 ; ++i){
        mid = (lo+hi) >> 1;
        if(can(mid)) lo = mid+1, ans = mid;
        else hi = mid-1;
    }
 
    print(ans);
    return 0;
}