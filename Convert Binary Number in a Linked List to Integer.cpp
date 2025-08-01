//T.C : O(n)
class Solution {
public:
    int getDecimalValue(ListNode* head) {
      int res = 0;
      while(head){
        res = (res<<1) | (head->val);
        head = head -> next;
      }  
      return res;
    }
};
