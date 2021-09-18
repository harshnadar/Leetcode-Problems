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
    int sizeOfList(ListNode* h){
        int i=0;
        while(h!=NULL){
            i++;
            h=h->next;
        }
        return i;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* h = new ListNode(0);
        h->next=head;
        int x = sizeOfList(h);
        cout<<x<<endl;
        // n--;
        n=x-n;
        int i=0;
        while(h!=NULL && i<n-1){
            i++;
            h=h->next;
        }
        // ListNode* tmp = new ListNode();
        // tmp->next = h->next;
        // h->next= tmp->next;
        h->next=h->next->next;
        if(n==1) return head->next;
        return head;
    }
};