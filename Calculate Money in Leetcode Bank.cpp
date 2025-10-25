//T.C : O(Q*7 + rem)) = O(n)
//S.C : O(1)
class Solution {
public:
    int totalMoney(int n) {
        vector<int>vec {1,2,3,4,5,6,7};
        int sum = 0;
        int Q = n / 7;
        while(Q){
            for(int i = 0; i < 7; i++){
                sum = sum + (Q - 1) + vec[i];
            }
            Q--;
        }
        int rem = n % 7;
        int newQ = (n/7) + 1;
        for(int i =0; i < rem; i++){
            sum = sum + (newQ - 1) + vec[i];
        }
        return sum;
    }
};

//Approach 1
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int totalMoney(int n) {
     int result  = 0;
     
     int monday_money = 1;
     
     while(n > 0){

        int money = monday_money;
        for(int day = 1; day <= min(n,7); day++){
            result += money;
            money++;
        }

        n -= 7;
        monday_money++;
     }
     return result;
     }
};

//Approach 2
//T.C : O(1)
//S.C : O(1)
class Solution {
public:
    int totalMoney(int n) {
      int terms = n/7; //weeks

      int first = 28;
      int last = 28 + (terms - 1)*7;

      int result = terms * (first + last)/2;

      int start_money = 1 + terms;

      for(int day = 1; day <= (n % 7); day++){
        result += start_money;
        start_money++;
      }
    return result;}
};

//Approach 3
//T.C : O(1)
//S.C : O(1)
class Solution {
public:
    int totalMoney(int n) {
     int terms = n/7;

     int first = 28;
     int last = 28 + (terms - 1)*7;

     int result = terms * (first + last)/2;

     int remain = n%7;
     int first_term = (1 + terms);
     int last_term = first_term  + remain - 1;
     result += remain * (first_term + last_term)/2;

     return result;
     }
};
