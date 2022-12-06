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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL or head->next==NULL){
            return head;
        }
        ListNode* t=head->next->next;
        ListNode* temp=new ListNode(head->val);
        ListNode* ans=temp;
        
        while(t!=NULL){
            ListNode* n= new ListNode(t->val);
            temp->next=n;
            temp=n;
            if(t->next==NULL){
                break;
            }
            t=t->next->next;
        }
        t=head->next;
        while(t!=NULL){
            ListNode* n= new ListNode(t->val);
            temp->next=n;
            temp=n;
            if(t->next==NULL){
                break;                
            }
            t=t->next->next;
        }
        return ans;
        
    }
};