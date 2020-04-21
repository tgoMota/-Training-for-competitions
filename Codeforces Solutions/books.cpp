//https://codeforces.com/problemset/problem/279/B
//B. Books || Codeforces
#include <bits/stdc++.h>
using namespace std;
const int m = 1e5+7;
typedef long long ll;
ll t, book[m];
int mx, n;

int main(){
    cin >> n >> t;
    for(int i = 1; i <= n ; ++i){
        cin >> book[i];
        book[i] += book[i-1];
    }

    for(int i = 1, j = 0; i <= n ; ++i){
        ll total = book[i]-book[j];
        if(total > t){
            j++;
            continue;
        }
        mx = max(mx,i-j);
    }

    printf("%d\n", mx);

    return 0;
}