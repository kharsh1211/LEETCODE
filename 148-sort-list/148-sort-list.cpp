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
      ListNode* merge(ListNode* l1, ListNode* l2){
    ListNode* dumy = new ListNode(-1);
    ListNode* cur = dumy;
    
    while(l1!=NULL && l2 != NULL){
        if(l1->val < l2->val){
            cur->next = l1;
            l1 = l1->next;
        }
        else {
            cur->next = l2;
            l2 = l2->next;
        }
        cur = cur->next;
    }
    if(l1 != NULL) cur->next = l1;
    if(l2 != NULL) cur->next = l2;
    
    return dumy->next;
}
ListNode* sortList(ListNode* head) {
    if(head == NULL || head->next == NULL) return head;
    
    ListNode* slow = head;
    ListNode* fast = head->next;
    
    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    fast = slow->next;
    slow->next = NULL;
    
    head = sortList(head);
    fast = sortList(fast);
    
    return  merge(head, fast);
	}
};