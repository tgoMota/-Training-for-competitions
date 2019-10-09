#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
int n, k, a[11];

int lis(int a[]){
    vector<int> aux(n+1,oo);
    aux[0] = -oo;
    for(int i = 0; i < n ; ++i){
        int j = upper_bound(aux.begin(), aux.end(), a[i]) - aux.begin();
        if(aux[j-1] < a[i] && a[i] < aux[j]) aux[j] = a[i];
    }
    int ans = 0;
    for(int i = 0; i <= n ; ++i)
        if(aux[i] < oo) ans = i;
    return ans;
}

int main(){
    cin >> n;
    for(int i = 0; i < n ; ++i) cin >> a[i];
    printf("%d\n", lis(a));

    return 0;
}