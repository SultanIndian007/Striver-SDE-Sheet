// O(n) + O(n%k~n), O(1)
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next|| k==0)return head;

        ListNode* temp = head;
        int count = 1;
        while(temp->next){
            temp = temp->next;
            count++;
        }
        temp->next =head;
        k = k%count;
        k = count -k;

        while(k--) temp = temp->next;
        head = temp->next;
        temp->next = NULL;

        return head;
    }
};