//T.C : O(n)
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
          if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* temp = head -> next;
        ListNode* prev = head;
        prev -> next = NULL;
        while(temp){
ListNode* dummy = temp;
temp = temp -> next;
dummy -> next = prev;
prev = dummy;
        }
        return prev;
    }
};
