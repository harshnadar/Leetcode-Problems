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
    bool hasCycle(ListNode *head) {
        map<ListNode*, int> mp;
        
        while(head!=NULL){
            if(mp.find(head)!=mp.end()) return true;
            mp[head]++;
            head = head->next;
        }
        // for(auto it: mp) cout<<it.second<<" ";
        return false;
    }
};