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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [](ListNode* a, ListNode* b) { return a->val > b->val; };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);
        for(auto it: lists){
            if(it) pq.push(it);
        }
        ListNode dummy(0);
        ListNode* tail = &dummy;
        while(!pq.empty()){
            ListNode* a = pq.top();
            pq.pop();
            tail->next = a;
            tail = tail->next;
            if(a->next) pq.push(a->next);
        }
        return dummy.next;
    }
};