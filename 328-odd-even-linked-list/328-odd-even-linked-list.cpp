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
        if(head==nullptr||head->next==nullptr||head->next->next==nullptr){
            return head;
        }
        int x = 0;
        ListNode *odd = head;
        ListNode *even = odd->next;
        ListNode *evenHead = even;
        ListNode *trav =even->next;
        while(trav->next!=nullptr){
            if(x==0){
                odd->next=trav;
                odd=odd->next;
                trav = trav->next;
                x=1;
            }
            else{
                even->next=trav;
                even=even->next;
                trav = trav->next;
                x=0;
            }
        }
            if(x==0){
                ListNode *hit = new ListNode(trav->val);
                odd->next=hit;
                odd=odd->next;
                even->next=nullptr;
            }
            else if(x==1){
                even->next=trav;
                even=even->next;
            }
        odd->next=evenHead;
        return head;
    }
};