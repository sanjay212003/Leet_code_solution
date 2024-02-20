//Remove Nth Node From End of List
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    int j=0;
    struct ListNode* temp=head;
    struct ListNode* prev;
    for(;temp!=NULL;temp=temp->next)
        j++;
    temp=head;
    if(j==n){
        if(head->next==NULL)
            return NULL;
        else{
            head=temp->next;
            return head;
        }
    }
    for(int i=1;i<j-n;i++)
        temp=temp->next;
    prev=temp;
    
    if(temp->next!=NULL){
        temp=temp->next;
        prev->next=temp->next;
    }
    else{
        prev->next=temp;
        temp=NULL;
    }
    
    free(temp);
    return head;
}
