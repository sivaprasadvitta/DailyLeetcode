class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head) return;
        
        ListNode *tmp = head, *slow = head, *prev = NULL;
        while (tmp->next && tmp->next->next) {
            tmp = tmp->next->next;
            slow = slow->next;
        }
        
        if (tmp->next) slow = slow->next;
        
        while (slow) {
            tmp = slow->next;
            slow->next = prev;
            prev = slow;
            slow = tmp;
        }
        slow = prev;
        
        while (head && slow) {
            tmp = head->next;
            prev = slow->next;
            head->next = slow;
            slow->next = tmp;
            head = tmp;
            slow = prev;
        }
        
        if (head && head->next) head->next->next = NULL;
    }
};