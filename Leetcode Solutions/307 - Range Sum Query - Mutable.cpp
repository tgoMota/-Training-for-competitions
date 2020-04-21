//https://leetcode.com/problems/range-sum-query-mutable/
//307. Range Sum Query - Mutable
class NumArray {
public:
    vector<int> tree;
    int sz;
    void build(int i, int l, int r, vector<int>& nums){
        if(l == r) tree[i] = nums[l];
        else{
            int m = (l+r)>>1;
            build(2*i, l, m, nums);
            build(2*i+1, m+1, r, nums);
            tree[i] = tree[2*i] + tree[2*i+1];
        }
    }
    
    void up(int i, int l, int r, const int p, const int x){
        if(l == r) tree[i] = x;
        else{
            int m = (l+r)>>1;
            if(p<=m) up(2*i, l, m, p, x);
            else up(2*i+1, m+1, r, p, x);
            tree[i] = tree[2*i] + tree[2*i+1];
        }
    }
    
    int query(int i, int l, int r, const int ql, const int qr){
        if(ql > r || qr < l) return 0;
        if(ql <= l && qr >= r) return tree[i];
        int m = (l+r)>>1;
        return query(2*i, l, m, ql, qr) + query(2*i+1, m+1, r, ql, qr);
    }
    
    
    NumArray(vector<int>& nums) {
        sz = nums.size();
        tree.resize(4*sz,0);
        if(sz) build(1,0,sz-1, nums);
    }
    
    void update(int i, int val) {
        up(1,0,sz-1, i, val);
    }
    
    int sumRange(int i, int j) {
        return query(1,0,sz-1, i, j);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */