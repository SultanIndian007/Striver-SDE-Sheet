// Brute force O(n) + O(n/2) -> traverse entire ll and calculate no of nodes.. then traverse n/2 again to get it coz on
// head is given, SC->O(1)
class Solution {
public:
    int length(ListNode*head){
        int len =0;
        while(head!=NULL){
            len++;
            head = head->next;
        }
        return len;
    }
    ListNode* middleNode(ListNode* head) {
        int len = length(head);
        int ans = len/2;

        ListNode*temp = head;
        int cnt = 0;
        while(cnt < ans){
            temp = temp->next;
            cnt++;
        }
        return temp;
    }
};

// Optimized approach
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast!=NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
};