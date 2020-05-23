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
        cin >> n;
        vector<int> even;
        vector<int> odd;
        bool ok = true;
        if(n <= 2){
            printf("NO\n");
        }else{
            int turn = 0;
            int l = 0;
            int num = 1;
            ll suma = 0LL, sumb = 0LL;
            while(l < n){
                if(turn % 2 == 0){ 
                    even.push_back(num+1);
                    odd.push_back(num);
                    suma += num+1;
                    sumb += num;
                }else{
                    even.push_back(num-1);
                    odd.push_back(num);
                    suma+=num-1;
                    sumb+=num;
                }
                l += 2;
                num += 4;
                turn++;
            }
            if(turn % 2 != 0){
                // suma -= even[0];
                // sumb -= odd[0];
                // even.erase(even.begin());
                // odd.erase(odd.begin());
                printf("NO\n");
            }
            else{
                printf("YES\n");
                for(int i = 0; i < even.size() ; ++i){
                    printf("%d ", even[i]);
                }
                for(int i = 0; i < odd.size(); ++i){
                    printf("%d", odd[i]);
                    if(i != odd.size()-1) printf(" ");
                }
                printf("\n");
            }
        }


        even.clear();
        odd.clear();
    }
    return 0;
}