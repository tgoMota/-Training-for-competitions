//https://www.urionlinejudge.com.br/judge/pt/problems/view/1310
//URI 1310 - Lucro
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, cd, a;
    vector<int> data;
    while(scanf("%d", &n) != EOF){
        scanf("%d", &cd);
        data.assign(n,-cd);
        for(int i = 0; i < n ; ++i){
            scanf("%d", &a);
            data[i]+=a;
        }

        int mx = 0, sum = 0;
        for(int i = 0; i < n ; ++i){
            sum += data[i];
            mx = max(mx,sum);
            if(sum < 0) sum = 0;
        }

        printf("%d\n", mx);
        data.clear();
    }


    return 0;
}