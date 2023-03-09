/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_map<ListNode*,int>m;
        ListNode*curr=head;
        while(curr!=NULL){
            if(m[curr]==true)
                return curr;
            else
                m[curr]++;
            curr=curr->next;
        }
        return NULL;
    }
};