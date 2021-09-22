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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return NULL;
        if(!head->next) return head;
        
        int val = head->val;
        ListNode* node = head->next;
        
        if(node->val!=val){
            head->next = deleteDuplicates(node);
            return head;
        }
        else{
            while(node && node->val == val){
                ListNode* p =node;
                node=node->next;
                delete(p);
            }
            return deleteDuplicates(node);
        }
        return head;
    }
};