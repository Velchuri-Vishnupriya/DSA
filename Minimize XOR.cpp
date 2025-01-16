//Approach-1
//T.C : O(long n)
//S.C : O(1);
class Solution{
public:
bool isset(int& x,int bit){return x & (1<<bit);}
bool setbit(int& x,int bit){return x|=(1<<bit);}
bool unsetbit(int& x,int bit){return x&= ~(1<<bit);}
    int minimizeXor(int num1, int num2) {
 int x=num1;
 int bit=0;
 int requiredsetbits=__builtin_popcount(num2);
 int currentsetbits=__builtin_popcount(num1);
 if(currentsetbits < requiredsetbits){
    while(currentsetbits<requiredsetbits){
        if(!isset(x,bit)){
            setbit(x,bit);
            currentsetbits++;
        }
        bit++;
    }
 }
 else if(currentsetbits>requiredsetbits){
    while(currentsetbits > requiredsetbits){
        if(isset(x,bit)){
            unsetbit(x,bit);
            currentsetbits--;
        }
        bit++;
    }
 }
 return x;
    }
};

//Approach-2
//T.S:O()
//S.C: O()
