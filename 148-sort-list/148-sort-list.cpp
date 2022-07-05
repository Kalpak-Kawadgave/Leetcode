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
    ListNode* sortList(ListNode* head) {
        auto trav = head;
        vector<int> arr;
        while(trav!=nullptr){
            arr.push_back(trav->val);
            trav=trav->next;
        }
        trav = head;
        sort(arr.begin(),arr.end());
        int i = 0;
        while(trav!=nullptr){
            trav->val = arr[i];
            i++;
            trav=trav->next;
        }
        return head;
    }
};