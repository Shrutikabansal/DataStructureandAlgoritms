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
    ListNode* removeNthFromEnd(ListNode* head, int m) {
        ListNode* temp = head;
        ListNode* prev = NULL;
        ListNode* next = head;
        int size = 0;

        while(temp!=NULL){
            size = size+1;
            temp = temp->next;
        }
        int n = size-m+1;

        temp = NULL;
        temp = head;
        for(int i=0;i<n-1;i++){
            prev = temp;
            temp = temp->next;
            // n--;
        }
        if(prev == NULL){
            head = head->next;
            return head;
        }

        prev->next = prev->next->next;

        return head;

    //     for (int i = 1; i < nodeFromBeginning; i++) {
    //     prev = temp;
    //     temp = temp->next;
    // }
    // if (prev == NULL) {
    //     head = head->next;
    //     return head;
    // }
    // else {
    //     prev->next = prev->next->next;
    //     return head;
    // }


        
    }
};