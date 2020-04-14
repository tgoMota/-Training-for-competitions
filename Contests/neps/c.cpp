#include <bits/stdc++.h>
using namespace std;
#define oo = 0x3f3f3f3f;
typedef long long ll;

bool isValid(int a, int b, int c){
    if(b >= a+c) return false;
    if(c >= a+b) return false;
    if(a >= b+c) return false;
    return true;
}
struct triangle{
    double area;
    int a;
    int b;
    int c;
};

double area(int a, int b, int c){
    int s = (a+b+c)/2;
    return sqrt(s*(s-a)*(s-b)*(s-c));
}
int main(){

    int n;
    cin >> n;
    vector<int> v(n);
    triangle t;
    t.area = 0.0;
    for(int i = 0; i < n ; ++i) scanf("%d", &v[i]);
    sort(v.begin(), v.end(), greater<int>());
    for(int i = 0; i < n ; ++i){
        for(int j = i+1; j < n ; ++j){
            for(int k = j+1 ; k < n ; ++k){
                if(area(v[i], v[j], v[k]) < t.area) break;
                if(isValid(v[i], v[j], v[k])) {
                    if(area(v[i], v[j], v[k]) > t.area){
                        t.area = area(v[i], v[j], v[k]);
                        t.a = v[i];
                        t.b = v[j];
                        t.c = v[k];
                        break;
                    }
                }
            }
        }
    }

    printf("%d %d %d\n", t.c, t.b, t.c);

    return 0;
}