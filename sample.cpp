class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
    while (head!=NULL && head->val == val){
head = head->next;}
        
        ListNode* newhead = head;
    if (head == NULL){
        return NULL;
    }
if (head->next == NULL){
    return head;
}
    
        while (head!=NULL && head->next != NULL){
        if (head->next->val == val){
            head->next = head->next->next;
        }
        else {head = head->next;
        }
        }
    if (head == NULL){
        return newhead;
    }
    else if (head->val == val){
        head = NULL;
    }
        return newhead;
    }
};
     