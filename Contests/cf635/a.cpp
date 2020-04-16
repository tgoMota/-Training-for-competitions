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

bool isValid(int a, int b, int c, int A, int B, int C, int D){
    if(a+b <= c) return false;
    if(a+c <= b) return false;
    if(b+c <= a) return false;
    if(a < A || a > B || b < B || b > C || c < C || c > D) return false;
    return true;
}

//A+C > B
//A+B > C
//B+C > A
 
int main(){
    int t;
    scanf("%d", &t);
    for(int ti = 1; ti <= t ; ++ti){
        int A, B, C, D;
        cin >> A >> B >> C >> D;
        bool ok = false;
        //a + b > c
        //b > c-a
        // c < a+b
        for(int i = B; i >= A ; --i){
            for(int j = C-i ; j <= C ; ++j){
                for(int k = i+j-1; k >=C ; --k){
                    if(isValid(i, j, k, A, B, C, D)){
                        printf("%d %d %d\n", i, j, k);
                        ok = true;
                        break;
                    }
                }
                if(ok) break;
            }
            if(ok) break;
        }
    }
    return 0;
}