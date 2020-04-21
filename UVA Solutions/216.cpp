#include <bits/stdc++.h>
using namespace std;

struct point {
    int x, y;
};

int n, c = 0;
double memo[10][1<<10];
const double oo = 0xfffffff;
vector<int> answer;

double distp(point a, point b){
    return 16.00+sqrt(pow(b.x-a.x,2) + pow(b.y-a.y,2));
}

double solve(int pos, int mask, vector<point>& points){
    if (mask == (1 << n) - 1) return 0.0;
    double& ans = memo[pos][mask];
    if(ans != -1) return ans;
    ans = oo;
    for(int i = 0; i < n ; ++i){
        if(i != pos && !(mask & (1 << i))) ans = min(ans, distp(points[i], points[pos]) + solve(i, mask | (1 << i), points));
    }
    return ans;
}

void back(int pos, int mask, vector<point>& points, double ans){
    if (mask == (1 << n) - 1) return ;
    for(int i = 0; i < n ; ++i){
        if((distp(points[i], points[pos]) + solve(i, mask | (1 << i), points)) == ans){
            answer.push_back(i);
            printf("(%d,%d)\n", points[i].x, points[i].y);
            back(i,mask | (1 << i), points, ans - distp(points[i], points[pos]));
            return ;
        }
    }
}

int main(){
    vector<point> points;
    double ans;
    while(scanf("%d", &n) && n){
        for(int i = 0; i < n ; ++i){
            point p;
            scanf("%d%d", &p.x, &p.y);
            points.push_back(p);
        }

        for(int i = 0; i < 10 ; ++i)
            for(int j = 0; j < (1 << 10) ; ++j) memo[i][j] = -1;

        //answer.assign(n);
        answer.push_back(0);
        ans = solve(0,1,points);
        back(0,1,points,ans);
        printf("Number of feet of cable required is %.2lf\n", ans);
        for(int i = 0; i < answer.size() ; ++i){
            printf("%d ", answer[i]);
        }
        points.clear();
        answer.clear();
    }
    return 0;
}