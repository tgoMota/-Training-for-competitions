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

int num(char a){
    return (a - '0');
}
int main(){
    string a;
    cin >> a;
    const int N = a.size();
    bool changed = true;
    while(changed){
        changed = false;
        for(int i = 0; i < N-2 ; ++i){
            if(num(a[i]) == 7 && abs(num(a[i])-num(a[i+1])) == 2){
                swap(a[i], a[i+1]);
                changed = true;
            }
        }
    }

    changed = true;
    while(changed){
        changed = false;
        for(int i = 1; i < N ; ++i){
            if(num(a[i]) == 5 && abs(num(a[i])-num(a[i-1])) == 2){
                swap(a[i], a[i-1]);
                changed = true;
            }
        }
    }

    changed = true;
    while(changed){
        changed = false;
        for(int i = 1; i < N ; ++i){
            if(num(a[i]) == 3 && abs(num(a[i])-num(a[i-1])) == 2){
                swap(a[i], a[i-1]);
                changed = true;
            }
        }
    }

    cout << a << endl;
    return 0;
}