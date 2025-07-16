 //T.C : O(n)
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode(-101);
        ListNode* curr = dummy;
     ListNode* temp, *temp1;

        temp = list1;
        temp1 = list2;
        while(temp && temp1){
if(temp -> val < temp1 -> val) {curr -> next = temp; curr = temp;temp = temp -> next; }
else {curr -> next = temp1;
curr = temp1;
temp1 = temp1 -> next;}
        }
        while(temp){
            curr -> next = temp;
            curr = temp;
            temp = temp -> next;
        }
        while(temp1){
            curr -> next = temp1;
            curr = temp1;
            temp1 = temp1 -> next;
        }
    return dummy -> next;}
};
