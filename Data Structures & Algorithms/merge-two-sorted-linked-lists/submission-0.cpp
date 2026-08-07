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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1) return list2;
        if (!list2) return list1;

        ListNode*head1=list1;
        ListNode*head2=list2;
        
        ListNode*merge;
        
        if(head1->val<=head2->val){
            merge=head1;
            head1=head1->next;
        }else{
            merge=head2;
            head2=head2->next;
        }
        ListNode*head=merge;
        while(head1&&head2){
            if(head1->val<=head2->val){
                merge->next=head1;
                head1=head1->next;
            }else{
                merge->next=head2;
                head2=head2->next;
            }
            merge=merge->next;
        }
        while(head1){
            merge->next=head1;
            merge=merge->next;
            head1=head1->next;
        }
        while(head2){
            merge->next=head2;
            merge=merge->next;
            head2=head2->next;
        }
        return head;
    }
};
