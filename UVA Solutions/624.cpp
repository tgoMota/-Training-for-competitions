#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f
#define ooLL 0x3f3f3f3f3f3f3f3f
#define fastio() ios_base::sync_with_stdio(false); cin.tie(0)
#define LOCAL
#ifdef LOCAL
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
#else
#define trace(...) 42
#endif
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
  cerr << name << ": " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << ": " << arg1 << " |";
  __f(comma + 1, args...);
}
const int mod = 1e9+7;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;

vector<int> tracks;
int back(int idx, int sum, int choosed, const int size, const int nt){
    if(idx == nt) return sum>size || choosed > 20 ? -oo : sum;
    return max(back(idx+1, sum+tracks[idx], choosed+1 ,size, nt), back(idx+1, sum, choosed ,size, nt));
}

void recover(int idx, int sum, int choosed, const int size, const int nt){
    if(idx == nt){
        printf("sum:%d\n", sum);
        return;
    }
    int a = back(idx+1, sum+tracks[idx], choosed+1 ,size, nt);
    int b = back(idx+1, sum, choosed, size, nt);
    if(a > b) {
        printf("%d ", tracks[idx]);
        recover(idx+1, sum+tracks[idx], choosed+1, size, nt);
    }else recover(idx+1, sum, choosed, size, nt);
}

int main(){
    int n;
    while(scanf("%d", &n)!=EOF){
        int nt;
        scanf("%d", &nt);
        tracks.resize(nt);
        for(int i = 0; i < nt ; ++i){
            scanf("%d", &tracks[i]);
        }
        recover(0,0,0,n,nt);
    }
    return 0;
}