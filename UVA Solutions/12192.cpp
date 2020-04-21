//Time limit =(
#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
int n, m, el, nquerys;
pair<int,int> query;
vector<int> v[501];
int main(){
    while(scanf("%d%d", &n, &m) && n+m){
        for(int i = 0; i < n ; ++i){
            for(int j = 0; j < m ; ++j){
                cin >> el;
                v[i].push_back(el);
            }
        }
        cin >> nquerys;
        while(nquerys--){
            cin >> query.first >> query.second; //interval
            int posx = 0, posy = 0, width = 0, height = 0, sz = 0, maxsz = 0, lastwidth = 0, maxwidth = oo, lastsz = 0;
            for(int j = 0; j < m-1 ; ++j){
                maxwidth = oo;
                for(int i = 0; i < n ; ++i){
                    height++;
                    if(v[i][j] < query.first || v[i][j] > query.second){
                        height = width = 0;
                        continue;
                    }
                    posy = upper_bound(v[i].begin()+j, v[i].end(), query.second)-v[i].begin()-1;//x <= query.second
                    width = posy - j+1;
                    maxwidth = min(maxwidth, width); //max possible width
                    sz = min(maxwidth,height); // possible size of square in this moment
                    maxsz = max(maxsz, sz);
                }
            }
            printf("%d\n", maxsz);
        }
        printf("-\n");
        if(nquerys) for(int i = 0; i < n ; ++i) v[i].clear();
    }

    return 0;
}