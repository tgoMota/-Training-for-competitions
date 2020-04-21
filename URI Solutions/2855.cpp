//https://www.urionlinejudge.com.br/judge/pt/problems/view/2855
//URI 2855 - Números de Sortes
//Solution O(n) - AC
#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, a, it;
    vector<int> v;
    while(scanf("%d", &n) != EOF){
        v.assign(n+1, 0);
        for(int i = 1; i <= n ; ++i) scanf("%d", &v[i]);
        scanf("%d", &a);

        bool ans = true;
        it = lower_bound(v.begin(), v.end(), a) - v.begin();
        for(int i = 2; i < n && it >= i ; ++i){
            if(it % i == 0){
                ans = false;
                break;
            }
            it = (it - it/i);
        }
        printf("%c\n", ans ? 'Y':'N');
    }

    return 0;
}

//Solution O(n^2) - TLE
// #include <bits/stdc++.h>
// using namespace std;

// int main(){
//     int n, a;
//     vector<int> v;
//     while(scanf("%d", &n) != EOF){
//         v.assign(n, 0);
//         for(int& x : v) scanf("%d", &x);
//         scanf("%d", &a);

//         for(int i = 1 ; i < v.size(); ++i)
//             for(int j = i; j < v.size() ; j=j+i)
//                 v.erase(v.begin()+j, v.begin()+j+1);

//         if(binary_search(v.begin(), v.end(), a)) printf("Y\n");
//         else printf("N\n");
//     }

//     return 0;
// }