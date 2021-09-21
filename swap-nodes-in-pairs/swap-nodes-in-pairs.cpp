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
    ListNode* swapPairs(ListNode* head) {
        ListNode* cur = head;
        ListNode* n=NULL;
        ListNode* prev = NULL;
        
        int count=0;
        int k=2;
        while(cur!=NULL && count<k){
            n=cur->next;
            cur->next = prev;
            prev=cur;
            cur=n;
            count++;
        }
        
        if(n!=NULL){
            head->next = swapPairs(n);
        }
        
        return prev;
    }
};