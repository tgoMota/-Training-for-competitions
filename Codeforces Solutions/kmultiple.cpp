//https://codeforces.com/contest/275/problem/C
//C. k-Multiple Free Set || Codeforces
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
map<ll,ll> num;
const int m = 1e5+7;
ll n, k, v[m], mx, cont;
int main(){
    cin >> n >> k;
    for(int i = 0; i < n ; ++i) cin >> v[i];
    sort(v,v+n);
    for(int i = n-1; i >= 0 ; --i)
        if(num.find(v[i]*k) == num.end()) num[v[i]] = 1;
    cout << num.size() << endl;
    return 0;
}