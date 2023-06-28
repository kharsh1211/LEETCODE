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
        ListNode*ptr=head;
        int count=0;
        while(ptr!=NULL){
            count++;
            ptr=ptr->next;
        }
        
        if(head==NULL && head->next==NULL)
            return NULL;
        
        if(count-n==0){
            head=head->next;
            return head;
        }
        
        ListNode*prev=head;
        ListNode*temp=head;
        
        for(int i=0;i<count-n;i++){
            prev=temp;
            temp=temp->next;
        }
        prev->next=temp->next;
        return head;
    }
};