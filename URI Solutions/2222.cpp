//https://www.urionlinejudge.com.br/judge/pt/problems/view/2222
//URI 2222 - Brincando com Conjuntos
// #include <bits/stdc++.h>
// using namespace std;

// int main(){

//     int t, n, k, q;
//     scanf("%d", &t);
//     while(t--){
//         scanf("%d", &n);
//         vector<int> c[n+1];
//         for(int i = 1; i <= n ; ++i){
//             scanf("%d", &k);
//             c[i].push_back(k);
//             for(int j = 0; j < c[i][0] ; ++j){
//                 scanf("%d", &k);
//                 c[i].push_back(k);
//             }
//         }
//         scanf("%d", &q);
//         unordered_set<int> co;
//         while(q--){
//             int a, b, d;
//             scanf("%d%d%d", &a, &b, &d);
//             co.clear();
//             for(int i = 1; i <= c[b][0] ; ++i) co.insert(c[b][i]);
//             for(int i = 1; i <= c[d][0] ; ++i) co.insert(c[d][i]);
//             if(a == 2) printf("%d\n", co.size());
//             else printf("%d\n", c[b][0]+c[d][0]-co.size());
//         }
//     }


//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

int main(){

    int t, n, k, q, sz;
    ll ans;
    vector<ll> m;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        m.assign(n+1, 0ULL);
        for(int i = 1; i <= n ; ++i){
            scanf("%d", &sz);
            for(int j = 1; j <= sz ; ++j){
                scanf("%d", &k);
                m[i] |= 1ull << k;
            }
        }

        scanf("%d", &q);
        for(int i = 0; i < q ; ++i){
            int a, b, c;
            ans = 0LL;
            scanf("%d%d%d", &a, &b, &c);
            
            if(a == 2) ans = m[b] | m[c];
            else ans = m[b] & m[c];

            printf("%d\n", __builtin_popcountll(ans));
        }
    }

    return 0;
}