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
    ListNode* removeNthFromEnd(ListNode* head, int n){
        stack<ListNode*> st;
        ListNode *p = head;
        while(head != NULL){
            st.push(head);
            head = head->next;
        }
        ListNode *forw = NULL;
        while(n > 0){
            forw = st.top();
            st.pop();
            n--;
        }
        if(!st.empty()){
            if(forw == p){
                p = p->next;
            }else{
                st.top()->next = forw->next;
            }
        }else{
            if(forw == NULL){
                return NULL;
            }else{
                p = forw->next;
            }
        }
        return p;
    }
};