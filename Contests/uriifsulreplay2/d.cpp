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

double area(int dX0, int dY0, int dX1, int dY1, int dX2, int dY2){
    double dArea = ((dX1 - dX0)*(dY2 - dY0) - (dX2 - dX0)*(dY1 - dY0))/2.0;
    return (dArea > 0.0) ? dArea : -dArea;
}

int main(){
    int t;
    scanf("%d", &t);
    for(int ti = 1; ti <= t ; ++ti){
       int x1, x2, x3, y1, y2, y3;
       scanf("%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3);
       printf("%.3lf\n", area(x1,y1,x2,y2,x3,y3));
    }
    return 0;
}