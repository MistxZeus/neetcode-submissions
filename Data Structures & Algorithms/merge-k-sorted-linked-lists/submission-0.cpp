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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0)return nullptr;
        
        while(lists.size()>1){
            vector<ListNode*>mergedList;
        for(int i=0;i<lists.size();i=i+2){
            ListNode*l1=lists[i];
            ListNode*l2;
            if(i+1<lists.size()){
                l2=lists[i+1];
            }else{
                l2=nullptr;
            }
            mergedList.push_back(mergeLists(l1,l2));
        }
            lists=mergedList;
        }
        return lists[0];
    }
    ListNode*mergeLists(ListNode*l1,ListNode*l2){
        ListNode*dummy=new ListNode(0);
        ListNode*curr=dummy;
        while(l1&&l2){
            if(l1->val<l2->val){
                curr->next=l1;
                l1=l1->next;
            }else{
                curr->next=l2;
                l2=l2->next;
            }
            curr=curr->next;
        }
        
        if(l1){
            curr->next=l1;
            l1=l1->next;
        }
        if(l2){
            curr->next=l2;
            l2=l2->next;
        }
        return dummy->next;
    }
    
};
