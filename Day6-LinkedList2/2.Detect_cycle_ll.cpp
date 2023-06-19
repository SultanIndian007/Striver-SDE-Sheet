// Optimal O(n), O(1)
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL || head->next == NULL)  
            return false;

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
            if(fast == slow)
                return true;
        }
    return false;
    }
};

// Brute force -> O(n), O(n)
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_map<ListNode* , ListNode*>mp;
        while(head!=NULL){
            if(mp.find(head) != mp.end()){
                return true;
            }
            else{
                mp[head] = head->next;
                head = head->next;
            }
        }
        return false;
    }
};