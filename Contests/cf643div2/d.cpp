#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
#define ooLL 0x3f3f3f3f3f3f3f3f
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL)
const int mod = 1e9+7;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> ii;
 
int main(){
 
    for(int ti = 1; ti <= 1 ; ++ti){
        int n, s, ns;
        scanf("%d%d", &n, &s);
        ns = s;
        vector<int> v(n);
        v[0] = 2;
        ns-=2;
        for(int i = 1; i < n ; ++i){
            if(i != n-1) v[i] = 2, ns-=2;
            else v[i] = ns; 
        }

        if(n == 1 && s == 1){
            printf("NO\n");
        }else if(n == 1){
            printf("YES\n");
            printf("%d\n", s);
            printf("%d\n", s-1);
        }else if(v.back() == 1 || v.back() <= 0){
            printf("NO\n");
        }else{
            printf("YES\n");
            for(int x : v) printf("%d ", x);
            printf("\n%d\n", 1);
        }
        //2 1 5 ,  k = 4
        //2 1 1 3 // s = 7
    }
    return 0;
}