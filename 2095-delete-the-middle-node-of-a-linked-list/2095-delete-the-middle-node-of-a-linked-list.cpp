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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* prev,*s=head,*f=head;
        if(!head->next) return nullptr;
        while(f and f->next){
            prev=s;
            s=s->next;
            f=f->next->next;
        }
        prev->next=prev->next->next;
        return head;
    }
};