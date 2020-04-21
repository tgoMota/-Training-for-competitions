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
map<int,int> g1;

bool cmp(pii& a, pii& b){
    return a.first > b.first;
}

int main(){
    int t;
    scanf("%d", &t);
    for(int ti = 1; ti <= t ; ++ti){
        int n;
        cin >> n;
        vector<pii> v(n);
        for(int i = 0; i < n ; ++i){
            int a;
            scanf("%d", &a);
            v[i] = {a, i};
        }
       // sort(v.begin(), v.end(), cmp);
        ll sum = 0LL;
        int max2x = -oo;
        bool passou = false;
        bool exist = false;
        for(int i = 0; i < n ; ++i){
            if(v[i].first < 0 && !passou) {
                max2x = max(max2x, v[i].first);
                exist = true;
            }
            if(v[i].first <= 0) continue;
            passou = true;
            int max1x = v[i].first;
            while(i < n && v[i].first > 0){
                max1x = max(max1x, v[i].first);
                i++;
            }
            sum+=max1x;
            for(int j = i; j < n ; ++j){
                if(v[j].first < 0) {
                    int maxx = v[j].first;
                    while(j < n && v[j].first < 0){
                        maxx = max(maxx, v[j].first);
                        j++;
                    }
                   // printf("somando %d e %d\n", max1x, maxx);
                    sum+=maxx;
                    i = j-1;
                    break;
                }
            }
        }

        if(exist) sum+=max2x;

        printf("%lld\n", sum);

    }
    return 0;
}