#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> a;
        sort(nums2.begin(), nums2.end());
        for(int i = 0; i < nums1.size() ; ++i) a.insert(nums1[i]);
        vector<int> ans;
        while(!a.empty()){
            int k = *a.begin();
            a.erase(a.begin());
            if(binary_search(nums2.begin(), nums2.end(), k)) ans.push_back(k);
        }
        return ans;
    }
};
int main(){
    vector<int> a, b, ans;
    int n1, n2, el;
    cin >> n1;
    for(int i = 0; i < n1 ; ++i){
        cin >> el;
        a.push_back(el);
    }
    cin >> n2;
    for(int i = 0; i < n2 ; ++i){
        cin >> el;
        b.push_back(el);
    }
    Solution s;
    ans = s.intersection(a,b);
    for(int i = 0; i < ans.size() ; ++i) printf("%d ", ans[i]);
    printf("\n");
    return 0;
}