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
    ListNode* insertionSortList(ListNode* head) {
        vector<int> v; 
        while(head){
            v.push_back(head->val);
            head = head->next;
        }
        
        sort(v.begin(), v.end());
        ListNode* p = new ListNode(0);
        ListNode* link = p;
        
        for(auto it: v){
            ListNode* u = new ListNode();
            u->val = it;
            u->next = NULL;
            p->next = u;
            p=p->next;
        }
        p->next = NULL;
        return link->next;
    }
};