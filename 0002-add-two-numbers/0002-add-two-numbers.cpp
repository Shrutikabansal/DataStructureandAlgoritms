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

        ListNode* dummy = new ListNode();
        ListNode* temp = dummy;

        int carry = 0, total = 0;

        while(l1 != NULL || l2!= NULL || carry){
            total = carry;

            if(l1){
                total += l1->val;
                l1 = l1->next;
            }
            if(l2){
                total += l2->val;
                l2 = l2->next;
            }

            // total = total + carry;
            carry = total/10;
            int addi = total%10;
            temp->next = new ListNode(addi);
            temp = temp->next;
        }

        // ListNode *res = ans->next;
        return dummy->next;



    }
};