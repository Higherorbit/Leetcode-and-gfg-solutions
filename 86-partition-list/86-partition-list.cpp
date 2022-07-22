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
    ListNode* partition(ListNode* head, int x) {
        auto t=head;
        vector<int> a;
        vector<int>b;
        while(t){
            if(t->val<x){
                a.push_back(t->val);
            }
            else{
                b.push_back(t->val);
            }
            t=t->next;
        }
        t=head;
        for(auto x:a){
            t->val=x;
            t=t->next;
        }
        for(auto x:b){
            t->val=x;
            t=t->next;
        }
        return head;
    }
};