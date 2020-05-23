//https://codeforces.com/gym/102157/problem/1
//1. Nuclear Reactor
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> ans;
int can(ll mid, ll k, vector<ll>& v){
    ans.clear();
    ll sum = 0LL;
    ans.push_back(v[0]);
    k--;
    for(int i = 0; i < v.size()-1 && k ; ++i){
        sum += v[i+1]-v[i]; //4 5 11 8 10
        if(sum >= mid){
            k--;
            sum = 0LL;
            ans.push_back(v[i+1]);
        }
    }
    return k == 0;
}
 
int main(){
    int n, k;
    cin >> n >> k;
    vector<ll> v(n);
    for(ll& x : v) scanf("%lld", &x);
    sort(v.begin(), v.end());
    ll lo = 0LL, hi = v.back(), mid;
    while(lo < hi){
        mid = lo + (hi-lo)/2LL;
        if(can(mid, k, v)) lo = mid+1;
        else hi = mid;
    }
 
    can(lo-1, k, v);
    for(int i = 0; i < ans.size() ; ++i){
        printf("%lld", ans[i]);
        if(i != (int)ans.size()-1) printf(" ");
    }
    printf("\n");
 
    return 0;
}