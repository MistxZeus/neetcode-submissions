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
    private:
    ListNode*reverseList(ListNode*head){
       ListNode*prev=nullptr;
       ListNode*curr=head;
       while(curr){
        ListNode*temp=curr->next;
        curr->next=prev;
        prev=curr;
        curr=temp;
       }
       return prev;
    }
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode dummy(0);
        dummy.next=head;
        ListNode*prev=&dummy;
        for(int i=0;i<left-1;i++){
            prev=prev->next;
        }
        ListNode*sublist_head=prev->next;
        ListNode*sublist_tail=sublist_head;
       
        for(int i=0;i<right-left;i++){
            sublist_tail=sublist_tail->next;
        }
        ListNode*nextNode=sublist_tail->next;
        sublist_tail->next=nullptr;
        prev->next=reverseList(sublist_head);
        sublist_head->next=nextNode;

        return dummy.next;
    }
};