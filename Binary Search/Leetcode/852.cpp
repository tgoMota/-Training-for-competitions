#include <bits/stdc++.h>
using namespace std;

//Solution O(logn) -  Binary Search
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int hi = A.size()-1, lo = 1, mid;
        while(lo<hi){
            mid = (lo+hi) >> 1;
            if(A[mid] < A[mid+1]) lo = mid+1;
            else hi = mid;
        }
        return lo; 
    }
};

//Solution O(n)
// class Solution {
// public:
//     int peakIndexInMountainArray(vector<int>& A) {
//         int sz = A.size();
//         for(int i = 1; i < sz-1 ; ++i){
//             if(A[i] > A[i-1] && A[i] > A[i+1]) return i;
//         }
//         return -1;
//     }
// };



int main(){
    int n, k;
    vector<int> ans;
    cin >> n;
    for(int i = 0; i < n ; ++i){
        cin >> k;
        ans.push_back(k);
    }
    Solution a;
    printf("%d\n",a.peakIndexInMountainArray(ans)); 
    return 0;
}