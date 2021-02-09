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
//CHECK THE LIMITS, PLEASE
struct point{
  int x, y;
  point(){};
  point(int _x, int _y){
    x = _x;
    y = _y;
  }
};

struct segment{
  point start, end;
  segment(){};
  segment(point _start, point _end){
    start = _start;
    end = _end;
  }

  void print(){
    printf("start = {%d,%d}, end = {%d,%d}\n", start.x,start.y, end.x, end.y);
  }
};

struct rectangle{
  point bottom_right, bottom_left, top_right, top_left;
  segment left, right, top, bottom;
  rectangle(){};
  rectangle(point _top_left, point _bottom_right){
    bottom_right = _bottom_right;
    top_left = _top_left;
    int y_bottom_left = bottom_right.y;
    int x_bottom_left = top_left.x;
    bottom_left = point(x_bottom_left, y_bottom_left);
    int y_top_right = _top_left.y;
    int x_top_right = bottom_right.x;
    top_right = point(x_top_right, y_top_right);

    left = segment(top_left, bottom_left);
    bottom = segment(bottom_left, bottom_right);
    right = segment(top_right, bottom_right);
    top = segment(top_left, top_right);
  }

  void print(){
    printf("REC:\n");
    printf("left: ");
    left.print();
    printf("right: ");
    right.print();
    printf("top: ");
    top.print();
    printf("bottom: ");
    bottom.print();
  }
};

int orientation(point& a, point& b, point& c){
  int o = (b.y-a.y)*(c.x-b.x) - (b.x-a.x)*(c.y-b.y);
  if(o == 0) return 0;
  return  o < 0 ? -1 : 1;
}
// int orientation(point p1, point p2, point p3) 
// { 
//     // See 10th slides from following link for derivation 
//     // of the formula 
//     int val = (p2.y - p1.y) * (p3.x - p2.x) - 
//               (p2.x - p1.x) * (p3.y - p2.y); 
  
//     if (val == 0) return 0;  // colinear 
  
//     return (val > 0)? 1: 2; // clock or counterclock wise 
// } 
bool intersect(segment a, segment b){
  point p1 = a.start, p2 = a.end, p3 = b.start, p4 = b.end;
  return (orientation(p1, p2, p3) != orientation(p1,p2,p4)) && (orientation(p3,p4,p1) != (orientation(p3,p4,p2)));
}



int main(){
    int t;
    scanf("%d", &t);
    for(int ti = 1; ti <= t ; ++ti){
        int start_x, start_y, end_x, end_y;
        scanf("%d%d%d%d", &start_x, &start_y, &end_x, &end_y);
        int top_left_x, top_left_y, bottom_right_x, bottom_right_y;
        scanf("%d%d%d%d", &top_left_x, &top_left_y, &bottom_right_x, &bottom_right_y);
        segment l = segment(point(start_x, start_y), point(end_x, end_y));
        rectangle r = rectangle(point(top_left_x, top_left_y), point(bottom_right_x, bottom_right_y));
        bool has_intersection = intersect(r.left, l) || intersect(r.right, l) || intersect(r.top, l) || intersect(r.bottom, l);
        printf("%s\n", has_intersection ? "T" : "F");
    }
    return 0;
}
