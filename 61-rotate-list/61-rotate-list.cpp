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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL or k==0){
            return head;
        }
        auto t=head;
        int len=1;
        while(t->next){
            t=t->next;
            len++;
        }
        cout<<len<<endl;
        t->next=head;
        k=k%len;
        int cnt=1;
        t=head;
        while(cnt<len-k){
            t=t->next;
            cnt++;
        }
        cout<<t->val<<endl;
        head=t->next;
        t->next=NULL;
        return head;
    }
};