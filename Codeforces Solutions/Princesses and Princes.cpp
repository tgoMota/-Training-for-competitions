//http://codeforces.com/contest/1327/problem/B
//B. Princesses and Princes

#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
#define ooLL 0x3f3f3f3f3f3f3f3f
#define mod 1e9+7
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
typedef long long ll;
typedef vector<pair<int,int>> vii;
typedef pair<int,int> pii;
 
int main(){
    int t;
    scanf("%d", &t);
    for(int ti = 1; ti <= t ; ++ti){
        int n;
        scanf("%d", &n);
        unordered_map<int,bool> took;
        vector<int> nevertook;
        vector<set<int>> v(n+1);
        for(int i = 1; i <= n ; ++i){
            int k;
            scanf("%d", &k);
            for(int j = 0; j < k ; ++j){
                int a;
                scanf("%d", &a);
                v[i].insert(a);
            }
           bool ok = false;
           for(int x : v[i]){
               if(!took[x]){
                   took[x] = ok = true;
                   break;
               }
           }

           if(!ok) nevertook.push_back(i);
            
        }

        if(took.size() == n) printf("OPTIMAL\n");
        else {
            printf("IMPROVE\n");
            printf("%d", nevertook[0]);
            for(int i = 1; i <= n ; ++i){
                if(took[i] == false){
                    printf(" %d", i);
                    break;
                }
            }
            printf("\n");
        }
    }
    return 0;
}