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
    void reorderList(ListNode* head) {
        if(head==NULL) return;

        ListNode*curr=head;
        stack<ListNode*>st;
        while(curr!=NULL){
            st.push(curr);
            curr=curr->next;
        }   
        int n=st.size()/2;
        curr=head;
        while(n--){
            ListNode*node=st.top();
            st.pop();

            ListNode* temp=curr->next;
            curr->next=node;
            node->next=temp;
            curr=temp;

        } 
        curr->next=NULL;
    }
};