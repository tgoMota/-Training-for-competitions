//https://leetcode.com/problems/product-of-the-last-k-numbers/
//1352. Product of the Last K Numbers
class ProductOfNumbers {
public:
    vector<int> v;
    ProductOfNumbers() {
        v.clear();
    }
    
    void add(int num) {
        v.push_back(num);
    }
    
    int getProduct(int k) {
        int ans = 1, sz = v.size();
        for(int i = 0; i < sz ; ++i){
            if(i >= sz-k) ans*= v[i];
        }
        return ans;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */