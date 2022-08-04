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
        if(head==NULL){
            return false;
        }
        ListNode* d=new ListNode();
        d->next=head;
        auto s=d;
        auto f=d;
        while(s==d or s!=f){
            s=s->next;
            if(f==NULL or f->next==NULL){
                return false;
            }
            
            f=f->next->next;            
        }
        return true;
    }
};