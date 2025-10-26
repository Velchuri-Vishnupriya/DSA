//T.C : O(1)
//S.C : O(n)
class Bank {
public:
vector<long long> Balance;
int n;
    Bank(vector<long long>& balance) {
        Balance = balance;
        n = Balance.size();
    }
    
    bool transfer(int account1, int account2, long long money) {
        if(account1 <= n && account2 <= n){
            if(Balance[account1 - 1] >= money){
                Balance[account1 - 1]-=money;
                Balance[account2 - 1] += money;
                return true;
            }
        }
        return false;
    }
    
    bool deposit(int account, long long money) {
         if(account > n || account < 1) return false;
        Balance[account - 1] += money;
        return true;
    }
    
    bool withdraw(int account, long long money) {
        if(account > n || account < 1) return false;
        if(Balance[account - 1] >= money){
            Balance[account - 1] -= money;
            return true;
        }
        return false;
    }
};
