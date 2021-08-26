//UVa 00920 - Sunny Mountains
//https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1204
#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-9;

struct point{
    double x, y;
    point() { x = y = 0.0; }
    point(double _x, double _y) : x(_x), y(_y) {}
    bool operator<(point other) const{ // override less than operator
        return x > other.x;
    }

    bool operator==(point other) const {
        return (fabs(x - other.x) < EPS && (fabs(y - other.y) < EPS));
    }
};
// second criteria, by y-coordinate

struct line { double a, b, c; };
// a way to represent a line
// the answer is stored in the third parameter (pass by reference)
void pointsToLine(point p1, point p2, line &l) {
    if (abs(p1.x - p2.x) < EPS) {
        // vertical line is fine
        l.a = 1.0;
        l.b = 0.0;
        l.c = -p1.x;
        // default values
    } else {
        l.a = -(double)(p1.y - p2.y) / (p1.x - p2.x);
        l.b = 1.0;
        // IMPORTANT: we fix the value of b to 1.0
        l.c = -(double)(l.a * p1.x) - p1.y;
    } 
}

double dist(point p1, point p2){
    // Euclidean distance
    // hypot(dx, dy) returns sqrt(dx * dx + dy * dy)
    return hypot(p1.x - p2.x, p1.y - p2.y);
}

// point rotate(point p, double theta){
//     double rad = DEG_to_RAD(theta);
//     // multiply theta with PI / 180.0
//     return point(p.x * cos(rad) - p.y * sin(rad),
//                  p.x * sin(rad) + p.y * cos(rad));
// }

bool areParallel(line l1, line l2){
    // check coefficients a & b
    return (fabs(l1.a - l2.a) < EPS) && (fabs(l1.b - l2.b) < EPS);
}
bool areSame(line l1, line l2){
    // also check coefficient c
    return areParallel(l1, l2) && (fabs(l1.c - l2.c) < EPS);
}

bool areIntersect(line l1, line l2, point &p){
    if (areParallel(l1, l2)) return false;
    // no intersection
    // solve system of 2 linear algebraic equations with 2 unknowns
    p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
    // special case: test for vertical line to avoid division by zero
    if (fabs(l1.b) > EPS) p.y = -(l1.a * p.x + l1.c)/l1.b;
    else p.y = -(l2.a * p.x + l2.c)/l2.b;
    return true;
}

struct vec{
    double x, y; // name: ‘vec’ is different from STL vector
    vec(double _x, double _y) : x(_x), y(_y) {}
};
vec toVec(point a, point b){
    // convert 2 points to vector a->b
    return vec(b.x - a.x, b.y - a.y);
}
vec scale(vec v, double s){
    return vec(v.x * s, v.y * s);
}
// nonnegative s = [<1 .. 1 .. >1]
// shorter.same.longer
point translate(point p, vec v){
    // translate p according to v
    return point(p.x + v.x, p.y + v.y);
}

double dot(vec a, vec b) { return (a.x * b.x + a.y * b.y); }
double norm_sq(vec v) { return v.x * v.x + v.y * v.y; }
// returns the distance from p to the line defined by
// two points a and b (a and b must be different)
// the closest point is stored in the 4th parameter (byref)
double distToLine(point p, point a, point b, point &c){
    // formula: c = a + u * ab
    vec ap = toVec(a, p), ab = toVec(a, b);
    double u = dot(ap, ab) / norm_sq(ab);
    c = translate(a, scale(ab, u));
    // translate a to c
    return dist(p, c);
}

// returns the distance from p to the line segment ab defined by
// two points a and b (still OK if a == b)
// the closest point is stored in the 4th parameter (byref)
double distToLineSegment(point p, point a, point b, point &c){
    vec ap = toVec(a, p), ab = toVec(a, b);
    double u = dot(ap, ab) / norm_sq(ab);
    if (u < 0.0){
        c = point(a.x, a.y);
        // closer to a
        return dist(p, a);
    }
    // Euclidean distance between p and a
    if (u > 1.0){
        c = point(b.x, b.y);
        // closer to b
        return dist(p, b);
    }
    // Euclidean distance between p and b
    return distToLine(p, a, b, c);
}
// run distToLine as above

double angle(point a, point o, point b){ // returns angle aob in rad
    vec oa = toVec(o, a), ob = toVec(o, b);
    return acos(dot(oa, ob) / sqrt(norm_sq(oa) * norm_sq(ob)));
}

double cross(vec a, vec b) { return a.x * b.y - a.y * b.x; }
// note: to accept collinear points, we have to change the ‘> 0’
// returns true if point r is on the left side of line pq
bool ccw(point p, point q, point r){
    return cross(toVec(p, q), toVec(p, r)) > 0;
}
// returns true if point r is on the same line as the line pq
bool collinear(point p, point q, point r){
    return fabs(cross(toVec(p, q), toVec(p, r))) < EPS;
}
typedef long long ll;
int main(){
    point m;
    while(cin >> m.x >> m.y){
        int n;
        cin >> n;
        double ans = 1e20;
        point last, pans;
        cin >> last.x >> last.y;
        for(int i = 0; i < n ; ++i){
            point cur, p;
            cin >> cur.x >> cur.y;

            double d = distToLineSegment(m, cur, last, p);
            if(d < ans){
                ans = d;
                pans = p;
            }
            last = cur;
        }
        cout << setprecision(4) << fixed;
        cout << pans.x << '\n' << pans.y << '\n';
    }
    return 0;
}