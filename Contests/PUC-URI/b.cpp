#include <bits/stdc++.h>
using namespace std;

// int calceq(int a, int b, int c){
//     int delta = b*b - 4*a*c;
//     int x1 = (-b + sqrt(delta))/(2*a);
//     int x2 = (-b - sqrt(delta))/(2*a);

// }

int main(){
    int n, k;
    scanf("%d%d", &n,&k);
    vector<int> v(n, 0), ans(n, 0);
    for(int& x: v) scanf("%d", &x);

    for(int i = 0; i < k ; ++i){
        for(int j = 0; j < n ; ++j) ans[j]+=v[j];
        if(i == k-1) break;
        ans.insert(ans.begin(), ans.back());
        ans.erase(ans.end()-1);
    }
    for(int i = 0; i < ans.size() ; ++i){
        printf("%d", ans[i]);
        if(i != ans.size()-1) printf(" ");
    }
    printf("\n");
    return 0;
}