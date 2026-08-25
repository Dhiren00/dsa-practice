class Solution {
public:

    ListNode* merge(ListNode* left, ListNode* right)
    {
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;

        while(left != NULL && right != NULL)
        {
            if(left->val < right->val)
            {
                tail->next = left;
                left = left->next;
            }
            else
            {
                tail->next = right;
                right = right->next;
            }

            tail = tail->next;
        }

        while(left != NULL)
        {
            tail->next = left;
            tail = tail->next;
            left = left->next;
        }

        while(right != NULL)
        {
            tail->next = right;
            tail = tail->next;
            right = right->next;
        }

        return dummy->next;
    }


    ListNode* mergeSort(ListNode* head)
    {
        if(head == NULL || head->next == NULL)
        {
            return head;
        }

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* previous = NULL;

        while(fast != NULL && fast->next != NULL)
        {
            previous = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        previous->next = NULL;

        ListNode* left = mergeSort(head);
        ListNode* right = mergeSort(slow);

        return merge(left, right);
    }


    ListNode* sortList(ListNode* head)
    {
        return mergeSort(head);
    }
};