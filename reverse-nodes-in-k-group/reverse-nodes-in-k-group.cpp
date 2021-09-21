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
    int length(ListNode* node){
        int count=0;
        while(node!=NULL){
            count++;
            node=node->next;
        }
        return count;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(length(head)<k) return head;
        ListNode* cur =  head;
        ListNode* n = NULL;
        ListNode* prev = NULL;
        
        int count = 0;
        
        while(cur!=NULL && count<k){
            n=cur->next;
            cur->next =prev;
            prev=cur;
            cur=n;
            count++;
        }
        if(n!=NULL) head->next = reverseKGroup(n,k);
        return prev;
    }
};