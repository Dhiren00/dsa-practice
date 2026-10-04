/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next==NULL)
        {
            return NULL;
        }
        ListNode* fast=head;
        int i=0;
        while(fast!=NULL)
        {
            fast=fast->next;
            i++;
        }
        if(n == i) {
            return head->next;
        }
        int z = 0;
        ListNode* previous = head;
        ListNode* slow = head;
        while (i - z > n) {              // runs len-n times
            previous = slow;
            slow = slow->next;
            z++;
        }
        if(slow==NULL||slow->next==NULL)
        {
            previous->next=NULL;
        }
        else
        {
            previous->next=slow->next;
        }
        return head;


    }
};