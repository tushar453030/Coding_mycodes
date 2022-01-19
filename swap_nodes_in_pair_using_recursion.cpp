    void swap(ListNode* &head){
        if(head==NULL || head->next==NULL){
            return;
        }
        ListNode* a=head->next;
        
        head->next=head->next->next;
        a->next=head;
        head=a;
        swap(head->next->next);
        
    }
    ListNode* swapPairs(ListNode* head) {
        swap(head);
        return head;
    }
