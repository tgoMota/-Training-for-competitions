// #include <bits/stdc++.h>
// using namespace std;
// #define oo 0x3f3f3f3f

// int t, d, n, memo[101][101][101],re[101], c;
// vector<int> car;
// vector<pair<int,int> >car2;
// vector<pair<int,int> >r;

// bool cmp(pair<int,int> a, pair<int,int> b){
//     return a.first > b.first;
// }

// bool cmp2(pair<int,int> a, pair<int,int> b){
//     return a.second < b.second;
// }

// int pd(int ind, int left, int right){
//     if(left > c || right > c) return -oo;
//     if(ind == car.size()) return 0;
//     int& ans = memo[ind][left/100][right/100];
//     if(ans != -1) return ans;
//     return ans = max({pd(ind+1, left+car2[ind].first, right) + 1, pd(ind+1, left, right+car2[ind].first) + 1, pd(ind+1, left, right)});
// }

// void recover(int ind, int left, int right){
//     if(ind == car.size()) return;
//     int leftP = pd(ind+1, left+car2[ind].first, right) + 1;
//     int rightP = pd(ind+1, left, right+car2[ind].first) + 1;
//     int no = pd(ind+1, left, right);
//     if(max({leftP, rightP, no}) == leftP){
//         r.push_back(car2[ind]);
//         re[car2[ind].second] = 0;
//         recover(ind+1, left+car2[ind].first, right);
//     }else if(max({leftP, rightP, no}) == rightP){
//         r.push_back(car2[ind]);
//         re[car2[ind].second] = 1;
//         recover(ind+1, left, right+car2[ind].first);
//     }else{
//         recover(ind+1, left, right);
//     }
// }

// int main(){
//     cin >> t;
//     while(t--){
//         cin >> c;
//         c *= 100;
//         int i = 0;
//         while(scanf("%d", &d) && d) {
//             car.push_back(d);
//             car2.push_back({d,i});
//             i++;
//         }
//         sort(car2.begin(), car2.end(), cmp);
        
//         memset(memo, -1, sizeof(memo));
//         printf("%d\n", pd(0,0,0));
//         recover(0,0,0);
//         sort(r.begin(), r.end(), cmp2);
//         for(i = 0; i < r.size() ; ++i){
//             if(re[r[i].second] == 0) printf("port\n");
//             else printf("starboard\n");
//         }
//         if(t) printf("\n");
//     }

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
#define oo 0x3f3f3f3f

int t, d, n, memo[200][200], c;
vector<int> car;

int pd(int ind, int left, int right, int cont){
    if(left > c || right > c) return -oo;
    if(ind == car.size()) return cont;
    //int& ans = memo[ind][left/100][right/100];
    int& ans = memo[ind][cont];
    if(ans != -1) return ans;
    return ans = max({pd(ind+1, left+car[ind], right, cont+1), pd(ind+1, left, right+car[ind], cont+1), pd(ind+1, 0, 0, 0)});
}

void recover(int ind, int left, int right, int cont){
    if(ind == car.size()) return;
    int leftP = pd(ind+1, left+car[ind], right, cont + 1);
    int rightP = pd(ind+1, left, right+car[ind], cont + 1);
    int no = pd(ind+1, 0, 0, 0);
    if(max({leftP, rightP, no}) == leftP && leftP > 0){
        printf("port\n");
        recover(ind+1, left+car[ind], right, cont+1);
    }else if(max({leftP, rightP, no}) == rightP && rightP > 0){
        printf("starboard\n");
        recover(ind+1, left, right+car[ind], cont+1);
    }else{
        recover(ind+1, 0, 0, 0);
    }
}

int main(){
    cin >> t;
    while(t--){
        cin >> c;
        c *= 100;
        while(scanf("%d", &d) && d)
            car.push_back(d);
        
        memset(memo, -1, sizeof(memo));
        printf("%d\n", pd(0,0,0,0));
        recover(0,0,0,0);
        if(t) printf("\n");
    }

    return 0;
}