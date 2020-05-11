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
        int n, k;
        scanf("%d%d", &n,&k);
        vector<int> v(n+1);
        for(int i = 1; i <= n ; ++i) scanf("%d", &v[i]);
        int mx = -1, freq = -1, interval = -1;
        for(int i = 1; i <= n ; ++i){
            int maxx = -1, newfreq = -1;
            for(int j = i+1; j < i+k-1 && i+k-1<=n ; ++j){
                if(v[j] == maxx) newfreq++;
                else if(v[j] > maxx){
                    maxx = v[j];
                    newfreq = 1;
                }
            }

            if((maxx > mx && newfreq == freq) || (newfreq > freq)){
                mx = maxx;
                freq = newfreq;
                interval = i;

                printf("em i = %d, mx = %d, freq = %d\n", i, mx, freq);
            }
        }

        printf("%d %d\n", freq+1, interval);

    }
    return 0;
}