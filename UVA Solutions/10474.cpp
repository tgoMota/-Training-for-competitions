//https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1415
#include <bits/stdc++.h>
using namespace std;
int n, q, x, clk;
vector<int> marb;
queue<int> fila;
int main(){
    while(scanf("%d%d", &n,&q) != EOF){
        if(n+q == 0) break;
        if(clk) marb.clear();
        for(int i = 0; i < n ; ++i){
            scanf("%d", &x);
            marb.push_back(x);
        }
        for(int i = 0; i < q ; ++i){
            scanf("%d", &x);
            fila.push(x);
        }
        sort(marb.begin(), marb.end());
        printf("CASE# %d:\n", ++clk);
        while(!fila.empty()){
            x = fila.front();
            fila.pop();
            vector<int>::iterator low = lower_bound(marb.begin(), marb.end(), x);
            if(*low == x) printf("%d found at %d\n", x,low - marb.begin()+1);
            else printf("%d not found\n", x); 
        }
    }

    return 0;
}
