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
    ListNode* partition(ListNode* head, int x) {
        ListNode*curr=head;
        int count=0;
        vector<int>list;
        while(curr!=NULL){
            list.push_back(curr->val);
            curr=curr->next;
        }
        int n=list.size();
        vector<int>list2;
        for(int i=0;i<n;i++){
            if(list[i]<x){
                list2.push_back(list[i]);
            }    
        }
        for(int i=0;i<n;i++){
            if(list[i]>=x){
                list2.push_back(list[i]);
            }    
        }
        
        
        
        ListNode* newHead = new ListNode(0);
		ListNode* result = newHead;
		
		for (int num : list2) {
			result->next = new ListNode(num);
			result = result->next;
		}
		
		return newHead->next;
        
    }
};