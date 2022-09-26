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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* start = new ListNode(0);
        ListNode* now = start;
        int a = 0, b = 0;
        while(l1 || l2 ){
            a = 0;
            if(l1 != nullptr)
                a += l1->val;
            if(l2!= nullptr)
                a += l2->val;
            a += b;
            if(a>=10){
                a -= 10;
                b = 1;
            }
            else{
                b = 0;
            }
            now->next = new ListNode(a);
            now = now->next;
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }
        if(b){
            now->next = new ListNode(1);
        }
        return start->next;
        
    }
};