class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        vector<int> hi;

        ListNode* temp = head;

        // store values
        while (temp != nullptr) {
            hi.push_back(temp->val);
            temp = temp->next;
        }

        ListNode* head1 = nullptr;
        ListNode* curr = nullptr;

        // rebuild reversed list
        for (int i = hi.size() - 1; i >= 0; i--) {
            ListNode* newNode = new ListNode(hi[i]);

            if (head1 == nullptr) {
                head1 = newNode;
                curr = newNode;
            } else {
                curr->next = newNode;
                curr = newNode;
            }
        }

        return head1;
    }
};