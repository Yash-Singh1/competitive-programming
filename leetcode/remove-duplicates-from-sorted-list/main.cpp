class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) {
            return head;
        }
        ListNode* cphead{head};
        int lsint{head->val};
        while (cphead->next) {
            if (cphead->val == cphead->next->val) {
                cphead->next = cphead->next->next;
            } else {
                cphead = cphead->next;
            }
        }
        return head;
    }
};
