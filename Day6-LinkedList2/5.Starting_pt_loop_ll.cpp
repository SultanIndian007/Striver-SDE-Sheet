// O(n), O(1)
// IMP-> 2(l1+l2) = l1+l2+nc
// l1 = nc -l2

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {

        if(head == NULL || head->next==NULL){
            return NULL;
        }
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* temp = head;

        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;

            if(fast == slow){
                while(slow!=temp){
                    slow = slow->next;  
                    temp = temp->next;
                }
                return slow;
            }
        }
    return 0;
    }
};