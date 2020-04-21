#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll t, n, m, k, p[200][200], c, maxcust, maxarea, sum, areasum;
int main(){
    scanf("%lld", &t);
    c = t;
    while(t--){
        scanf("%lld%lld%lld", &n, &m, &k);
        for(int i = 0; i < n ; ++i){
            for(int j = 0 ; j < m ; ++j){
                scanf("%lld", &p[i][j]);
                if(j > 0) p[i][j] += p[i][j-1];
            }
        }
        maxarea = maxcust = 0LL;
        for(int i = 0; i < m ; ++i){
            for(int j = i; j < m ; ++j){
                sum = areasum = 0LL;
                for(int row = 0 ; row < n ; row++){
                    if(i > 0) sum += p[row][j] - p[row][i-1];
                    else sum += p[row][j];
                    if(sum > k){
                        areasum = sum = 0LL;
                        if(i > 0 && p[row][j] - p[row][i-1] > k) continue;
                        if(i == 0 && p[row][j] > k) continue;
                        if(i > 0) sum += p[row][j] - p[row][i-1];
                        else sum += p[row][j];
                    }
                    areasum += (ll)(j-i+1);
                    if(areasum > maxarea) maxarea = areasum, maxcust = sum;
                    else if(areasum == maxarea && maxcust > sum) maxcust = sum;         
                }
            }
        }
        printf("Case #%lld: %lld %lld\n", c-t, maxarea, maxcust);
    }

    // 372635 403776 757342 613647 255624 827769 988581 15911 261777 184255
    // 78024 387910 348870 200215 585883 814196 380850 444434 610663 873209
    // 210084 734511 355740 416582 27004 585921 880676 188471 270919 377865
    // 549570 643554 781641 823264 257201 553617 167385 762134 85880 945514
    // 946389 680257 333425 811611 396824 919308 625808 777674 363742 236471
    // 167236 90178 487334 522976 506760 514339 108897 387437 219162 379816
    // 765302 285084 23371 63296 624700 796924 133265 792085 559059 219146

//     14 4 23
// 10 10 0 5
// 5 1 5 7
// 4 4 15 17
// 0 2 6 18
// 11 14 17 10
// 12 4 1 8
// 3 1 16 2
// 14 19 4 16
// 1 4 13 6
// 5 11 13 2
// 7 1 11 0
// 3 9 18 6
// 3 7 8 16
// 12 10 4 15

    return 0;
}