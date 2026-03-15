class Fancy {
public:
long long M = 1e9 + 7;
typedef long long ll;
ll add = 0;
ll mult = 1;
vector<ll> seq;
//Binary Exponentiation using Fermats little throren a^(p-2) mod p
long long power(long long a, long long b){
    if(b == 0)return 1;

    long long half = power(a, b/2);
    long long result = (half * half) % M;

    if(b%2 == 1){
        result = (result * a) % M;
    }

    return result;
}
    Fancy() {
       
    }
    
    void append(int val) {//log(M-2)
        long long x = ((val - add) % M + M)*power(mult, M-2)%M;
        seq.push_back(x);
    }
    
    void addAll(int inc) {
        add = (add + inc) % M;
    }
    
    void multAll(int m) {
        add = (add * m) % M;
        mult = (mult * m) % M;
    }
    
    int getIndex(int idx) {
        return (idx >= 0 && idx < seq.size()) ? (seq[idx] * mult + add) % M : -1;
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */
