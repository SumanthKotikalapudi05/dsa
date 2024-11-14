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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL||head->next==NULL)
        return NULL;
        ListNode* temp=head;
        int c=0;
        while(temp!=NULL){
            temp=temp->next;
            c++;
        }
        int ind=c-n-1;
        int i=0;
        if(n==c){
            head=head->next;
            return head;
        }
        temp=head;
        while(temp!=NULL){
            if(i==ind){
                temp->next=temp->next->next;
            }
            temp=temp->next;
            i++;
        }
        return head;
    }
};