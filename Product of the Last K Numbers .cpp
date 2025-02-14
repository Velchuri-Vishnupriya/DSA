//Brute Force
class ProductOfNumbers {
public:
    ProductOfNumbers() {}
    vector<int> nums;
    void add(int num) {
        nums.push_back(num);
    }
    
    int getProduct(int k) {
        int prdt=1;
        int n=nums.size();
        for(int i=n-k;i<n;i++){
prdt*=nums[i];
        }
        return prdt;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */

//optimal Approach
class ProductOfNumbers {
public:
    vector<int> nums;

    ProductOfNumbers() {}

    void add(int num) {
        if (num == 0) {
            nums.clear();  // Reset when 0 is encountered
        } else {
            if (nums.empty()) nums.push_back(num);
            else nums.push_back(nums.back() * num);
        }
    }

    int getProduct(int k) {
        int n = nums.size();
        if (k > n) return 0; 
        if (k == n) return nums[n-1]; 
        return nums[n-1] / nums[n-k-1];
    }
};
