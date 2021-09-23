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
        map<ListNode*, int> mp;
        int i=0;
        while(head!=NULL){
            if(mp.find(head)!=mp.end()) return head;
            mp[head]=i;
            head = head->next;
            i++;
        }
        return NULL;
    }
};