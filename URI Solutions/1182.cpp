#include <bits/stdc++.h>
using namespace std;

int main(){
    int c;
    cin >> c;
    char ch;
    cin >> ch;
    double ans = 0.0, k;
    for(int i = 0; i < 12 ; ++i){
        for(int j = 0; j < 12 ; ++j){
            scanf("%lf", &k);
            if(j == c) ans+=k;
        }
    }
    if(ch == 'S') printf("%.1lf\n", ans);
    else printf("%.1lf\n", ans/12.0);

    return 0;
}