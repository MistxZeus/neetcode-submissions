class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1 = l1, *temp2 = l2;
        int len1=0,len2=0;
        while(temp1){
            len1++;
            temp1=temp1->next;
        }
        while(temp2){
            len2++;
            temp2=temp2->next;
        }
        ListNode*merged,*res;
        if(len1>=len2){
            merged=l1;
            res=l1;
        }else{
            merged=l2;
            res=l2;
        }
        int carry=0;
        while(l1 && l2){
            int sum=l1->val+l2->val+carry;
            merged->val=sum%10;
            carry=sum/10;
            
            if (merged->next == nullptr && carry > 0) {
                merged->next = new ListNode(carry);
                carry = 0;
            }
            l1=l1->next;
            l2=l2->next;
            merged=merged->next;
        }
        while(carry==1){
            int sum=merged->val+1;
            merged->val=sum%10;
            carry=sum/10;
            if(carry == 1 && merged->next == nullptr){
                merged->next = new ListNode(1);
                carry = 0;
            }
            merged=merged->next;
        }
        return res;
    }
};